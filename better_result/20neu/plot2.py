import sys
import pandas as pd
import matplotlib.pyplot as plt


num_neuron = int(sys.argv[1])
name = ['time']
for i in range(num_neuron):
    name.append('neu' + str(i))
data = pd.read_csv('./compare/FiringRateALLavg.dat', delim_whitespace=True, names = name)

plt.figure()
for i in range(num_neuron):
    plt.plot(data['time'], data.iloc[:, i+1])
plt.xlabel('Time (ms)', size=14)
plt.ylabel('Firing rate(Hz)', size=14)

filename = './compare/firingrate_avg.png'
plt.savefig(filename, format='png', bbox_inches='tight', dpi=300)
