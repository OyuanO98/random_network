#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

struct neu
{
    char name[17];
    unsigned int num_last, num_next;
    vector<const char*> last, next;
    neu()
    {
        num_last = num_next = 0;
    }
};

short check_condition(neu&, neu&);
bool connect_two(neu&, neu&);
bool outputfile(FILE*, neu&);

int main(int argc, char* argv[])
{
    /*input information*/
    unsigned int num_neuron, at_least_connecton;
/*    printf("How many neurons are there in this network? :");
    scanf("%u", &num_neuron);
    printf("How many connection are there in a neuron? :");
    scanf("%u", &at_least_connecton);*/
    num_neuron = atoi(argv[1]);
    at_least_connecton = atoi(argv[2]);

    /*create, initialize neurons*/
    srand(time(0));
    neu* neuron_list = new neu[num_neuron];
    unsigned int i, j; //counter
    for(i=0; i<num_neuron; i++)
    {
        sprintf(neuron_list[i].name, "neuron%u", i);
        neuron_list[i].num_last = rand()%(num_neuron-at_least_connecton)+at_least_connecton;
        neuron_list[i].num_next = rand()%(num_neuron-at_least_connecton)+at_least_connecton;
    }

    /*create network*/
    /*least connection first build*/
    unsigned int num;
    short rerandom;
    for(i=0; i<at_least_connecton; i++)
    {
        for(j=0; j<num_neuron; j++)
        {
            num = rand()%num_neuron;
            do
            {
                rerandom = check_condition(neuron_list[j], neuron_list[num]);
                rerandom = rerandom || (j==num);
                if(rerandom)
                {
                    num++;
                    if(num>=num_neuron)
                        num %= num_neuron;
                }
            }
            while(rerandom);
            connect_two(neuron_list[j], neuron_list[num]);
        }
    }

    /*other build*/
    neu nullconnection;// null connection
    nullconnection.num_last = nullconnection.num_next = 4294967295;
    strcpy(nullconnection.name, "//");
    unsigned int cnt, nextcheck, lastcheck;
    do
    {
        nextcheck = 0;
        for(i=0; i<num_neuron; i++)
        {
            num = rand()%num_neuron;
            cnt = num_neuron;
            if(check_condition(neuron_list[i], neuron_list[num]) == -1)
                continue;
            do
            {
                rerandom = check_condition(neuron_list[i], neuron_list[num]);
                rerandom = rerandom || (i==num);
                if(rerandom)
                {
                    num++;
                    cnt--;
                    if(num>=num_neuron)
                        num %= num_neuron;
                }
            }
            while(rerandom && cnt);
            if(!cnt)
                connect_two(neuron_list[i], nullconnection);
            else
                connect_two(neuron_list[i], neuron_list[num]);
            nextcheck += neuron_list[i].num_next;
        }
    }while(nextcheck>0);

    /*deal with num_last>0*/
    for(i=0; i<num_neuron; i++)
    {
        while(neuron_list[i].num_last>0)
            connect_two(nullconnection, neuron_list[i]);
    }

    /*filename*/
    char filename[31] = "./result/network";
    strcat(filename, argv[3]);
    strcat(filename, ".txt");
    FILE* network = fopen(filename, "w");
    fprintf(network, "%u\n", num_neuron);
    for(i=0; i<num_neuron; i++)
    {
        outputfile(network, neuron_list[i]);
        fprintf(network, "endneu\n");
    }
    fclose(network);
    delete []neuron_list;
    return 0;
}

short check_condition(neu& nlast, neu& nnext)
{
    if(nlast.num_next>0 && nnext.num_last>0)
        return 0;
    else if(nlast.num_next == 0)
        return -1;
    else
        return 1;
}

bool connect_two(neu& nlast, neu& nnext)
{
    nlast.next.push_back(nnext.name);
    nlast.num_next--;
    nnext.last.push_back(nlast.name);
    nnext.num_last--;
    return true;
}

bool outputfile(FILE* file, neu& neuron)
{
    fprintf(file, "%s\n", neuron.name);
    unsigned int conti;
    if(neuron.last.size()>neuron.next.size())
    {
        for(conti=0; conti<neuron.next.size(); conti++)
        {
            fprintf(file, "%u %s %s\n", conti, neuron.last[conti], neuron.next[conti]);
        }
        do
        {
            fprintf(file, "%u %s no\n", conti, neuron.last[conti]);
            conti++;
        }while(conti<neuron.last.size());
    }
    else if(neuron.last.size()==neuron.next.size())
    {
        for(conti=0; conti<neuron.next.size(); conti++)
        {
            fprintf(file, "%u %s %s\n", conti, neuron.last[conti], neuron.next[conti]);
        }
    }
    else
    {
        for(conti=0; conti<neuron.last.size(); conti++)
        {
            fprintf(file, "%u %s %s\n", conti, neuron.last[conti], neuron.next[conti]);
        }
        do
        {
            fprintf(file, "%u no %s\n", conti, neuron.next[conti]);
            conti++;
        }while(conti<neuron.next.size());
    }
    return true;
}
