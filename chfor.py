import re

with open("./network.txt", "r") as of:
    lines = of.readlines()
line = lines[0]
pren = []
postn = []
with open("./network3.txt", "w") as mf:
    mf.write("seed:\n")
    mf.write(line)
    for j in range(1, len(lines)):
        line = lines[j]
        if(line[0] == 'n'):
            neu = re.findall('[0-9]+', line)
            neu = neu[0]
        elif(line[0] == 'e'):
            mf.write("N" + neu + " " + str(len(pren)) + " " + str(len(postn)) + "\n")
            mf.write("i: ")
            for i in range(len(pren)):
                out = re.findall('[0-9]+', pren[i])
                out = out[0]
                mf.write("N" + out + " ")
            mf.write('\n')
            mf.write("o: ")
            for i in range(len(postn)):
                out = re.findall('[0-9]+', postn[i])
                out = out[0]
                mf.write("N" + out + " ")
            mf.write('\n')
            pren.clear()
            postn.clear()
        else:
            line = line.split()
            pre = line[1]
            post = line[2]
            if(pre != "no" and pre != "//"):
                pren.append(pre)
            if(post != "no" and post != "//"):
                postn.append(post)