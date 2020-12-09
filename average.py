import pandas as pd
import sys

num_file = int(sys.argv[1])
avg = pd.read_csv("./compare/FiringRateALL1.dat", sep=' ')
for i in range(2, num_file+1):
    buff = pd.read_csv("./compare/FiringRateALL" + str(i) + ".dat", sep=' ')
    avg.iloc[:, 1:20] = avg.iloc[:, 1:20] + buff.iloc[:, 1:20]
    del buff
avg.iloc[:, 1:20] = avg.iloc[:, 1:20]/num_file
avg.to_csv("./compare/FiringRateALLavg.dat", header=False, index=False, sep=' ')
