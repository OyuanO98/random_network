#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int comp (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char* argv[])
{
    fstream net, netmod;
    string filename("./better_result/type1/network");
    filename += argv[1];
    filename += ".txt";
    net.open(filename, ios::in);

    string line;
    unsigned num_neurn, num_synapse;
    getline(net, line);
    net >> num_neurn >> num_synapse;

    unsigned num_chg = num_synapse*0.1;
    unsigned* chg_list = new unsigned[num_chg];
    unsigned seed = static_cast<unsigned>(time(0));
    srand(seed);
    for(unsigned i=0; i<num_chg; i++)
    {
        chg_list[i] = rand()%num_synapse + 1;
    }
    qsort(chg_list, num_chg, 4, comp);
    for(unsigned i=0; i<num_chg; i++)
        cout << chg_list[i] << '\n';
    cout.flush();
    return 0;
}