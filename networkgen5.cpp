//generate no repaet connections
#include <cstdio>
#include <cstring>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

/**********struct begin*********/
struct neu
{
    char name[12];
    vector <const char*> last, next;
    bool SetName(const char*);
    bool setConnection(neu&);
    bool isEqu(neu&);
    bool operator==(neu&);
    bool isInLast(neu&);
    bool isInNext(neu&);
};

bool neu::SetName(const char* neu_name)
{
    if(neu_name[0] == '\0')
    {
        printf("Warning: a neuron has no name.\n");
        return false;
    }
    strcpy(name, neu_name);
    return true;
}

bool neu::setConnection(neu& postsynaptic)
{
    if(postsynaptic.name[0] == '\0')
    {
        printf("invalid connect, no name neuron.\n");
        return false;
    }
    next.push_back(postsynaptic.name);
    postsynaptic.last.push_back(name);
    return true;
}

bool neu::isEqu(neu& a_neu)
{
    if(a_neu.name[0] == '\0')
    {
        printf("Target neuron has no name, compare rejected.\n");
        system("pause");
        exit(-1);
    }
    if(!strcmp(name, a_neu.name))
        return true;
    return false;
}

bool neu::operator==(neu& a_neu)
{
    if(!strcmp(name, a_neu.name))
        return true;
    return false;
}

bool neu::isInLast(neu& a_neu)
{
    unsigned int nlast = last.size();
    for(unsigned int i=0; i<nlast; i++)
    {
        if(!strcmp(last[i], a_neu.name))
            return true;
    }
    return false;
}

bool neu::isInNext(neu& a_neu)
{
    unsigned int nnext = next.size();
    for(unsigned int i=0; i<nnext; i++)
    {
        if(!strcmp(next[i], a_neu.name))
            return true;
    }
    return false;
}
/***********struct end***********/

bool check(neu&, neu&);

int main(int argc, char *argv[])
{
    unsigned int num_neuron = atoi(argv[1]);
    unsigned int totol_connection=0, one_connection, rnum;
    unsigned int i, j; //counter

    /*construct and initial neurons*/
    neu* neuron_list = new neu[num_neuron];
    for(i=0; i<num_neuron; i++)
    {
        sprintf(neuron_list[i].name, "N%u", i);
    }

    unsigned long seed = static_cast<unsigned long>(time(0));
    default_random_engine generator(seed);
    normal_distribution<float> ndis((unsigned)num_neuron*0.2, (unsigned)num_neuron*0.05);
    srand(seed);
    for(i=0; i<num_neuron; i++)
    {
        one_connection = ndis(generator);//************
        for(j=0; j<one_connection; j++)
        {
            rnum = rand()%num_neuron;
            while(rnum == i || check(neuron_list[i], neuron_list[rnum]))
            {
                rnum++;
                if(rnum >= num_neuron)
                    rnum -= num_neuron;
            }
            neuron_list[i].setConnection(neuron_list[rnum]);
            totol_connection++;
        }
    }

    FILE* StoreSeed = fopen("./seed.txt", "a");
    fprintf(StoreSeed, "%s %lu\n", argv[2], seed);
    fclose(StoreSeed);

    char filename[31] = "./result/network";
    strcat(filename, argv[2]);
    strcat(filename, ".txt");
    FILE* net = fopen(filename, "w");
    fprintf(net, "seed: %lu\n", seed);
    fprintf(net, "%u %u\n", num_neuron, totol_connection);
    unsigned int repeat;
    for(i=0; i<num_neuron; i++)
    {
        fprintf(net, "%s %lu %lu\n", neuron_list[i].name, neuron_list[i].last.size(), neuron_list[i].next.size());
        repeat = neuron_list[i].last.size();
        fprintf(net, "i: ");
        for(j=0; j<repeat; j++)
            fprintf(net, "%s ", neuron_list[i].last[j]);
        fprintf(net, "\n");
        repeat = neuron_list[i].next.size();
        fprintf(net, "o: ");
        for(j=0; j<repeat; j++)
            fprintf(net, "%s ", neuron_list[i].next[j]);
        fprintf(net, "\n");
    }
    fclose(net);

    delete []neuron_list;
    return 0;
}

bool check(neu& pre, neu& post)
{
    return pre.isInNext(post);
}
