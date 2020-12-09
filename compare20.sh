g++ chgnet.cpp -o chgnet.so -std=c++11

echo "What is the file number?"
read fnum

echo "How many times do you want to run?"
read time

rm -r ./compare
mkdir ./compare

cp "./better_result/20neu/network"$fnum".txt" ./compare
cp "./better_result/20neu/firingrate"$fnum".png" ./compare

./chgnet.so $fnum 1

for i in $(seq 1 $time)
do
    python3 ./better_result/20neu/chgconfpro.py $fnum $i
    ./flysim.out -conf network.conf -pro network.pro -nmodel LIF
done

python3 average.py $time
python3 ./better_result/20neu/plot2.py 20
