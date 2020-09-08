#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct neu
{
    char name[17];
    neu **last, **next;
    unsigned int last_num, next_num;
    neu()
    {
        last_num = next_num = 0;
    }
};

bool set_connection(neu&, unsigned int);
bool connect_two(neu&, neu&);
bool neuoutput(FILE*, neu&);

int main(int argc, char* argv[])
{
    /*input imformation*/
    unsigned int num_neuron, con;
/*    printf("How many neurons are there in the network? :");
    scanf("%u", &num_neuron);
    printf("How many connection in each neuron? :");
    scanf("%u", &con);
    /*file input*/
    num_neuron = atoi(argv[1]);
    con = atoi(argv[2]);

    /*create, initialize network*/
    neu* neuron_list = new neu[num_neuron];
    unsigned int i, j; //counter
    for(i=0; i<num_neuron; i++)
    {
        set_connection(neuron_list[i], con);
        sprintf(neuron_list[i].name, "neuron%u", i);
    }

    /*make connection*/
    srand(time(0));
    unsigned int num, cnt;
    bool rerandom;
    for(i=0; i<con; i++)
    {
        for(j=0; j<num_neuron; j++)
        {
            /*check condition*/
            rerandom = false;
            cnt = num_neuron;
            num = rand()%num_neuron;
            do
            {
                /*no over connect, no connect itself as possible*/
                rerandom = neuron_list[j].next_num>=con;
                rerandom = rerandom || neuron_list[num].last_num>=con;
                rerandom = rerandom || j==num;
                rerandom = rerandom && cnt;
                if(rerandom)
                {
                    num++;
                    cnt--;
                    if(num>=num_neuron)
                        num %= num_neuron;
                }
            }while(rerandom);
            /*check end*/
        connect_two(neuron_list[j], neuron_list[num]);
        }//end j for
    }//end i for

    /*create output file*/
    char filename[31] = "./result/network";
    strcat(filename, argv[3]);
    strcat(filename, ".txt");
    FILE* network = fopen(filename, "w");
    fprintf(network, "%u %u\n", num_neuron, con);
    for(i=0; i<num_neuron; i++)
        neuoutput(network, neuron_list[i]);
    fclose(network);
    delete []neuron_list;

    return 0;
}

bool set_connection(neu& neuron, unsigned int connection_num)
{
    neuron.next = new neu*[connection_num];
    neuron.last = new neu*[connection_num];
    return true;
}

bool connect_two(neu& nlast, neu& nnext)
{
    nlast.next[nlast.next_num] = &nnext;
    nlast.next_num++;
    nnext.last[nnext.last_num] = &nlast;
    nnext.last_num++;
    return true;
}

bool neuoutput(FILE* f, neu& neuron)
{
    fprintf(f, "%s\n", neuron.name);
    for(unsigned int i=0; i<neuron.next_num; i++)
        fprintf(f, "%u %s %s\n", i+1, neuron.last[i]->name, neuron.next[i]->name);
}
