#!/bin/bash

let NS=$1  # Startwert
let NE=$2  # Endwert
let DN=$3  # DELTA

# Dateiname fuer Ergebnisse
FILE="result_frac.dat"

# Alte Ergebnisdatei loeschen
if [ -e $FILE ]; then
rm $FILE
fi

# Schleife ueber Simulationsschritte
for i in $(seq $NS $DN $NE);
do
{
    # Erste Spalte: Simulationsschritt
    echo -n $i;

    # Leerzeichen
    echo -n " ";

    # Anteil besetzter Zellen pro S
    gawk '($3>0){SUM+=1} END{print SUM/NR}' field$i.dat

}>>result_frac.dat
done
