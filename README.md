# Wissenschaftliches-Programmieren
Arbeitsbereich fuer Vorlesung: Wissenschaftliches Programmieren fuer Ingenieure in KIT

## Uebung 1
sinus_plot.cxx  
generate a sequence of x and sin(x)

* input: 
  * (input has beed protected by checking its legality)
  * hw: the times of halfwave length
  * nsteps: number of sampling points

* output:
  * sequence of x and f(x)

## Uebung 2
1. fibonacci.cpp  
generate fibonacci sequence with the ratio of neighboring number
  * input:
    - count: number of numbers in generated sequence
  * output:
    - fibonacci sequence
    - ratio of neighboring number
2. MKinteg.cpp  
calculate the area of a circle using Monte Carlo Integration methode
  * input:
    - r: radius of a circle
  * outut:
    - area of the circle

## Uebung 3
using libary [Eigen3](eigen.tuxfamily.org)  
generate a matrix to simulate a 'game of life', ouput data can be plotted with GNUPLOT.
1. functions_game.h  
headfile of 'functions_game.cpp'
2. functions_game.cpp  
include 4 operations of a matrix:
  * create_field2d(x, y): generate a matrix of x rows and y columns
  * init_field2s(matrix, frac): randomly arrange the matrix with 0 and 1 where sum(1) / (x * y)
  * make_step(matrix1,matrix2): refresh the state of matrix1 with a temp matrix2
  * plot_field(matrix, n): output the matrix by given interval n
3. main_game.cpp  
main function, to start a game of life
4. Makefile
