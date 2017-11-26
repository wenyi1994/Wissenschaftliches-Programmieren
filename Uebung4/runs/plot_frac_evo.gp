file3(n) = sprintf("./frac0.3/config%d/result_frac.dat",i)
file5(n) = sprintf("./frac0.5/config%d/result_frac.dat",i)
file7(n) = sprintf("./frac0.7/config%d/result_frac.dat",i)

set grid
set key off
set xrange[0:100]
set yrange[0:1]
set xlabel 'Simulationsschritt [-]'
set ylabel 'frac'
set title 'Dichteentwicklung Game of Life Simulationsreihen mit frac=0.3/0.5/0.7'

pl for [i=1:10] file3(i) u 1:2 w l lc 1,\
for [i=1:10] file5(i) u 1:2 w l lc 2,\
for [i=1:10] file7(i) u 1:2 w l lc 3


