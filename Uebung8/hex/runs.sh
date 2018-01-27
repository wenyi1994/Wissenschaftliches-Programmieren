datei=$1

dirname=${datei%.*}
mkdir $dirname
cp hex40x50.dat ./$dirname/
cd $dirname

time ../../mdsim < ../$datei

cd ..