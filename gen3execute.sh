g++ networkgen3.cpp -o networkgen3.so

echo "How many neurons are there in this network?"
read num_neuron

echo "How many connections are at least in a neuron?"
read at_least_connection

echo "How many times do you want to execute?"
read time

rm network.conf network.pro ./result -r
mkdir ./result

for i in $(seq 1 $time)
do

./networkgen3.so $num_neuron $at_least_connection $i
python3 gen3_conf_pro.py $i

done
