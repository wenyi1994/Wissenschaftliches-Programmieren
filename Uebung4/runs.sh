frac=$1

mkdir runs
cd runs
mkdir frac$1
cd frac$1

for i in $(seq 1 10)

do echo "create config$i"
mkdir config$i
cd config$i

echo writing data ...
/home/yi/Documents/Uebung4/run_sim.sh $frac
echo -e "\n"
cd ..

done

cd ..
cd ..
