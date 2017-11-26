#!/bin/bash

FRAC=$1

cd runs/frac$FRAC

# Dateiname
FILE="result_frac_avrg.dat"
MID="all_frac.dat"

# Alte Ergebnisdatei loeschen
if [ -e $FILE ]; then
rm $FILE
fi

if [ -e $MID ]; then
rm $MID
fi

for i in $(seq 1 10)
do
{
	cd config$i
	cat result_frac.dat|awk '{print $2}'
	cd ..
}>>all_frac.dat
done

{
gawk '{line[(NR-1)%101]+=$1} END {for (j=0;j<101;j+=1){print j,line[j]/10}}' all_frac.dat
}>>result_frac_avrg.dat

rm $MID
cd ..
cd ..
