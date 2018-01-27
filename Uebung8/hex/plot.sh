echo "
    do for [ii=0:1000:1] {file =sprintf('lattice%d.dat',ii); pl file u 2:3 title file}
    " | gnuplot