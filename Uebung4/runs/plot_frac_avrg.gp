file3 = sprintf("./frac0.3/result_frac_avrg.dat")
file5 = sprintf("./frac0.5/result_frac_avrg.dat")
file7 = sprintf("./frac0.7/result_frac_avrg.dat")

set grid
set key off
set xrange[0:100]
set yrange[0:1]
set xlabel 'Simulationsschritt [-]'
set ylabel 'frac'
set title 'Dichteentwicklung Game of Life Simulationsreihen mit frac=0.3/0.5/0.7'

pl file3 u 1:2 w l lc 1,\
file5 u 1:2 w l lc 2,\
file7 u 1:2 w l lc 3

