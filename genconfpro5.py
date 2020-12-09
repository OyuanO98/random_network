from class_conf_pro import Network
import sys
import numpy

filename = "./result/network" + sys.argv[1] + ".txt"
with open(filename, "r") as f:
    netcon = f.readlines()

line = netcon[1]
line = line.split()
num_neuron = int(line[0])
num_synapse = int(line[1])
num_exci = round(num_synapse*0.75)
num_inhi = num_synapse - num_exci
count = int(0)

#build neurons
net = Network()
for i in range(num_neuron):
    name = "N" + str(i)
    net.add_neuron(name, 1, 0.5, 15, -70, -55, -50)

net.add_receptor('Ach', 20, 0, 0, 2.1, 1)
net.add_receptor('NMDA', 100, 0, 0, 2.1, 1)
net.add_receptor('AMPA', 2, 0, 0, 2.1, 1)
net.add_receptor('GABA', 5, -70, 0, 2.1, 1)
net.set_neuron_receptor_all('Ach')
net.set_neuron_receptor_all('GABA')

for i in range(2, len(netcon)):
    line = netcon[i]
    if(line[0] == 'N'):
        line = line.split()
        neu = line[0]
    elif(line[0] == 'o'):
        line = line.split()
        for j in range(1, len(line)):
            if(count <= num_exci):
                #(Pre_syn, Post_syn, TargetReceptor, MeanEff, weight)
                net.add_target(neu, line[j], 'Ach', 1.75, 1)
                count += 1
            else:
                net.add_target(neu, line[j], 'GABA', 0.5, 1)

# Generate pro file
Type_Mem = 'ChangeMembraneNoise'
Type_Freq = 'ChangeExtFreq'
Type_End = 'EndTrial'

#  (Time, Type, GaussMean, GaussSTD)
for i in range(10):
    net.add_event(200, Type_Mem, 'N' + str(i), 1, 0)
    net.add_event(300, Type_Mem, 'N' + str(i), 0, 0)
net.add_event(1000, Type_End)

net.add_output('./result/FiringRateALL' + sys.argv[1] + '.dat', 'FiringRate', 'AllPopulation' , 100, 10)
net.add_output('./result/SpikeALL' + sys.argv[1] + '.dat', 'Spike', 'AllPopulation')
net.add_output('./result/MemPot' + sys.argv[1] + '.dat', 'MemPot', 'AllPopulation')

net.output('network.conf', 'network.pro')
