g++ networkgen2.cpp -o networkgen2.so

echo "How many neurons are there in this network?"
read num_neuron

echo "How many connections are there in each neuron?"
read con

echo "How many times do you want to execute?"
read time

rm network.conf network.pro ./result -r
mkdir ./result

for i in $(seq 1 $time)
do
    ./networkgen2.so $num_neuron $con $i

    python3 gen_conf_pro.py $i

    /home/user/FlysimTutorial/bin/flysim.out -conf network.conf -pro network.pro -nmodel LIF

    python3 plot2.py $num_neuron $i
    
    sleep 1
done
