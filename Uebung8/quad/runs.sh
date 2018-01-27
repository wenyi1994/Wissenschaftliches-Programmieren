datei=$1

dirname=${datei%.*}
mkdir $dirname
cp quad40x40.dat ./$dirname/
cd $dirname

time ../../mdsim < ../$datei

cd ..