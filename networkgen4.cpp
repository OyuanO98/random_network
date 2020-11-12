#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

struct neu
{
    string name;
    vector <string> last, next;
//    vector <unsigned short> strlast, strnext; //connection strength
    bool SetName(string);
//    unsigned int findcon(neu&); //find connection
};

bool neu::SetName(string neu_name)
{
    if(neu_name.empty())
    {
        cout << "Warning: an unmaned neuron is constructed." << endl;
        return false;
    }
    name = neu_name;
    return true;
}

/***********struct neu end*************/

bool connect_two(neu&, neu&);

int main(int argc, char* argv[])
{
    unsigned int num_neuron = atoi(argv[1]);
    unsigned int at_least_connection = atoi(argv[2]);
    unsigned int totol_connection=0, one_connection, rnum;
    neu* neuron_list = new neu[num_neuron];
    unsigned int i, j; //counter

    /*initialize neuron name*/
    for(i=0; i<num_neuron; i++)
    {
        neuron_list[i].name = "N" + to_string(i);
    }

    /*random network*/
    srand(time(0));
    for(i=0; i<num_neuron; i++)
    {
        one_connection = rand()%(num_neuron - at_least_connection) + at_least_connection;
        for(j=0; j<one_connection; j++)
        {
            rnum = rand()%num_neuron;
            while(rnum == i)
                rnum = rand()%num_neuron;
            connect_two(neuron_list[i], neuron_list[rnum]);
            totol_connection++;
        }
    }

    /*output file*/
    fstream network;
    string filename = "./result/network";
    filename += argv[3];
    filename += ".txt";
    network.open(filename, ios::out);
    network << num_neuron << ' ' << totol_connection << '\n';
    for(i=0; i<num_neuron; i++)
    {
        network << neuron_list[i].name << "\ni " << neuron_list[i].last.size() << ' ';
        for(j=0; j<neuron_list[i].last.size(); j++)
        {
            network << neuron_list[i].last[j] << ' ';
        }
        network << "\no " << neuron_list[i].next.size() << ' ';
        for(j=0; j<neuron_list[i].next.size(); j++)
        {
            network << neuron_list[i].next[j] << ' ';
        }
        network << '\n' << "endneu" << "\n\n";
    }

    network.close();
    delete []neuron_list;
    return 0;
}

bool connect_two(neu& nlast, neu& nnext)
{
    nlast.next.push_back(nnext.name);
    nnext.last.push_back(nlast.name);
    return true;
}