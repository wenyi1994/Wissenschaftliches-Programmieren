file1A = sprintf("./ergebnis1A.dat")
file2A = sprintf("./ergebnis2A.dat")
file3A = sprintf("./ergebnis3A.dat")
file1B = sprintf("./ergebnis1B.dat")
file2B = sprintf("./ergebnis2B.dat")

set pm3d map

set term jpeg
set output '1A.jpg'
spl file1A u 1:2:3 with image
set term jpeg
set output '1B.jpg'
spl file1B u 1:2:3 with image
set term jpeg
set output '2A.jpg'
spl file2A u 1:2:3 with image
set term jpeg
set output '2B.jpg'
spl file2B u 1:2:3 with image
set term jpeg
set output '3A.jpg'
spl file3A u 1:2:3 with image