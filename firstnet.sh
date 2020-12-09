g++ networkgen5.cpp -o networkgen5.so

echo "How many neurons are there in this network?"
read num_neuron

echo "How many times do you want to execute?"
read time

rm network.conf network.pro ./result -r
mkdir ./result

for i in $(seq 1 $time)
do
    ./networkgen5.so $num_neuron $i

    python3 genconfpro5.py $i

    ./flysim.out -conf network.conf -pro network.pro -nmodel LIF

    python3 plot2.py $num_neuron $i
    
    sleep 1
done
