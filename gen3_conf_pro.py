from class_conf_pro import Network
import sys


#  Generate Network ---------------------------------------
net = Network()


with open("./result/network" + sys.argv[1] + ".txt", "r") as f:
    tit = f.readline()
    neuron = int(tit[0])
    for i in range(neuron):
        name = "neuron" + str(i)
        #  (Name, N, C, Taum, RestPot, ResetPot, Threshold)
        net.add_neuron(name, 1, 0.5, 15, -70, -55, -50)

#set receptor
    net.add_receptor('Ach', 20, 0, 0, 2.1, 1)
    net.add_receptor('NMDA', 100, 0, 0, 2.1, 1)
    net.add_receptor('AMPA', 2, 0, 0, 2.1, 1)
    net.add_receptor('GABA', 5, -70, 0, 2.1, 1)
    net.set_neuron_receptor_all('Ach')
    net.set_neuron_receptor_all('GABA')

#set connection
    for i in range(int(neuron*0.75)):
        name = f.readline()
        name = name.strip()  #remove '\n' in readline
        while 1 :
            next = f.readline()
            next = next.strip()
            if(next == "endneu"):
                break
            next = next.split()
            next = next[2]
            if(next == "//" or next == "no"):
                continue
            net.add_target(name, next, 'Ach', 5, 1)
    for i in range(int(neuron*0.75), neuron):
        name = f.readline()
        name = name.strip()  #remove '\n' in readline
        while 1 :
            next = f.readline()
            next = next.strip()
            if(next == "endneu"):
                break
            next = next.split()
            next = next[2]
            if(next == "//" or next == "no"):
                continue
            net.add_target(name, next, 'GABA', 1, 1)

# Generate pro file
Type_Mem = 'ChangeMembraneNoise'
Type_Freq = 'ChangeExtFreq'
Type_End = 'EndTrial'

#  (Time, Type, GaussMean, GaussSTD)
for i in range(10):
    net.add_event(200, Type_Mem, 'neuron' + str(i), 4, 0)
    net.add_event(300, Type_Mem, 'neuron' + str(i), 0, 0)
net.add_event(1000, Type_End)

net.add_output('FiringRateALL.dat', 'FiringRate', 'AllPopulation', 100, 10)
net.add_output('SpikeALL.dat', 'Spike', 'AllPopulation')
net.add_output('MemPot.dat', 'MemPot', 'AllPopulation')

net.output('network.conf', 'network.pro')

