#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

struct neu
{
    string name;
    unsigned num_last, num_next;
    vector<string> next;
};

int main(int argc, char* argv[])
{
    /*read network information*/
    fstream net, netmod;
    unsigned num_neuron, num_synapse;
    string filename = "./better_result/20neu/network";//<<<<<<<<<
    filename += argv[1];
    filename += ".txt";
    net.open(filename, ios::in);
    net.ignore(2147483647, '\n');
    net >> num_neuron >> num_synapse;
    net.ignore(2147483647, '\n');

    /*random generate number for changing connections*/
    unsigned num_chg = num_synapse*0.1;
    unsigned* chg_list = new unsigned[num_chg];
    unsigned seed = static_cast<unsigned>(time(0));
    default_random_engine generator(seed);
    uniform_int_distribution<unsigned> udis(1, num_synapse);
    for(unsigned i=0; i<num_chg; i++)
    {
        do//remove same number
        {
            chg_list[i] = udis(generator);
        }while(find(chg_list, chg_list+i, chg_list[i]) != chg_list+i);
    }
    sort(chg_list, chg_list+num_chg);

    /*create output networkmod.txt*/
    filename = "./compare/network";
    filename += argv[1];
    filename += "mod";
    filename += argv[2];
    filename += ".txt";
    netmod.open(filename, ios::out);
    netmod << "modseed: " << seed << '\n';
    netmod << num_neuron << ' ' << num_synapse << endl;
    
    /*input and deal with change*/
    string line;
    neu aneu;
    unsigned total=0, countchg=0, num_last, num_next;
    vector<string> had_chg;
    while(getline(net, line))
    {
        if(line[0] == 'N')
        {
            istringstream iline(line);
            iline >> aneu.name >> num_last >> num_next;
            if(total + num_next >= chg_list[countchg] && countchg < num_chg)
            {
                net.ignore(2147483647, '\n');//ignore input line
                getline(net, line);//get output line
                istringstream con(line);
                string node;
                con >> node;//remove o:
                while(con >> node)
                {
                    aneu.next.push_back(node);
                }
                do
                {
                    had_chg.push_back(aneu.next[(chg_list[countchg]-total-1)]);
                    bool rerand;
                    string newcon;
                    do
                    {
                        unsigned newnum = udis(generator)%num_neuron;
                        newcon = "N" + to_string(newnum);
                        rerand = (find(aneu.next.begin(), aneu.next.end(), newcon) != aneu.next.end());
                        rerand = rerand || (find(had_chg.begin(), had_chg.end(), newcon) != had_chg.end());
                    }while(rerand);
                    aneu.next[(chg_list[countchg]-total-1)] = newcon;//change
                    countchg++;
                }while(total + num_next >= chg_list[countchg] && countchg < num_chg);

                netmod << aneu.name << ' ' << num_last << ' ' << num_next << '\n';
                netmod << "i: \no: ";
                for(string i : aneu.next)
                {
                    netmod << i << ' ';
                }
                netmod << endl;
                total += num_next;
                aneu.next.clear();
                had_chg.clear();
            }
            else
            {
                total += num_next;
                net.ignore(2147483647, '\n');//ignore input line
                getline(net, line);
                netmod << aneu.name << ' ' << num_last << ' ' << num_next << '\n';
                netmod << "i: \n" << line << endl;
            }
        }
    }
    net.close();
    netmod.close();
    delete []chg_list;
    return 0;
}
