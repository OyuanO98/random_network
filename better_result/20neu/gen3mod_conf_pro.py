from class_conf_pro import Network
import random as rd
import sys


#  Generate Network ---------------------------------------
net = Network()


with open("./network" + sys.argv[1] + ".txt", "r") as f:
    line = f.readline()
    line = line.split()
    neuron = int(line[0])
    num_synapse = int(line[1])
    for i in range(neuron):
        name = "neuron" + str(i)
        #  (Name, N, C, Taum, RestPot, ResetPot, Threshold)
        net.add_neuron(name, 1, 0.5, 15, -70, -55, -50)
    num_chg = int(num_synapse*0.1)
    chg_list = rd.sample(range(1, num_synapse+1), num_chg) #list the synapse need changing
    

#set receptor
    net.add_receptor('Ach', 20, 0, 0, 2.1, 1)
    net.add_receptor('NMDA', 100, 0, 0, 2.1, 1)
    net.add_receptor('AMPA', 2, 0, 0, 2.1, 1)
    net.add_receptor('GABA', 5, -70, 0, 2.1, 1)
    net.set_neuron_receptor_all('Ach')
    net.set_neuron_receptor_all('GABA')

#set connection
    cntn=int(0)
    cntc=int(0)
    for i in range(int(neuron*0.75)):
        name = f.readline()
        name = name.strip('\n')  #remove '\n' in readline
        collect = {}
        had_chg = []
        while 1 :
            next = f.readline()
            next = next.strip('\n')
            if(next == "endneu"):
                break
            next = next.split()
            next = next[2]
            if(next == "//" or next == "no"):
                continue
            else:
                cntn = cntn + 1
                if cntn == chg_list[cntc]:
                    cntc = cntc + 1
                    had_chg.append(next)
                    next = 'neuron' + str(rd.choice(range(neuron)))
                    while(next in had_chg):
                        next = 'neuron' + str(rd.choice(range(neuron)))
            if(next in collect):
                collect[next] = collect[next] + 1
            else:
                collect[next] = 1
        for j in collect:
            net.add_target(name, j, 'Ach', 1, collect[j])
    for i in range(int(neuron*0.75), neuron):
        name = f.readline()
        name = name.strip('\n')  #remove '\n' in readline
        collect = {}
        while 1 :
            next = f.readline()
            next = next.strip('\n')
            if(next == "endneu"):
                break
            next = next.split()
            next = next[2]
            if(next == "//" or next == "no"):
                continue
            else:
                cntn = cntn + 1
                if cntn == chg_list[cntc]:
                    cntc = cntc + 1
                    had_chg.append(next)
                    next = 'neuron' + str(rd.choice(range(neuron)))
                    while(next in had_chg):
                        next = 'neuron' + str(rd.choice(range(neuron)))
            if(next in collect):
                collect[next] = collect[next] + 1
            else:
                collect[next] = 1
        for j in collect:
            net.add_target(name, j, 'GABA', 2, collect[j])
# Generate pro file
Type_Mem = 'ChangeMembraneNoise'
Type_Freq = 'ChangeExtFreq'
Type_End = 'EndTrial'

#  (Time, Type, GaussMean, GaussSTD)
for i in range(10):
    net.add_event(200, Type_Mem, 'neuron' + str(i), 4, 2)
    net.add_event(300, Type_Mem, 'neuron' + str(i), 0, 2)
net.add_event(1000, Type_End)

net.add_output('FiringRateALL.dat', 'FiringRate', 'AllPopulation', 100, 10)
net.add_output('SpikeALL.dat', 'Spike', 'AllPopulation')
net.add_output('MemPot.dat', 'MemPot', 'AllPopulation')

net.output('network.conf', 'network.pro')

