frac=$1

cd runs/frac$1

for i in $(seq 1 10)

do echo "calculating config$i..."
cd config$i
/home/yi/Documents/Uebung4/calc_frac.sh 0 100 1
cd ..
done

cd ..
cd ..
