# Wissenschaftliches-Programmieren
Arbeitsbereich fuer Vorlesung: Wissenschaftliches Programmieren fuer Ingenieure in KIT
### !!!After download please reset the path in `.sh` `include` or any other file!!!

> Update 2017/11/28  
> <Uebung4/runs.sh>(https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung4/runs.sh)  
> The directory of `runs/frac0.x` can be automatically created now.

## Uebung 4
Using `gawk` to realize reading / editing data in files.  
Here are some examples of shell command:  
```shell
echo Hello
echo -e "text \c \n"
for i in $(seq 1 5)
do{
    echo creating dir$i
    mkdir dir$i
    echo done!
}
done
```
### - Root Directory
1. [run_sim.sh](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung4/run_sim.sh)    
Startup file of `game of life`. The value of `frac` must be typed in (0.3/0.5/0.7). After execution a file named `conf_start` will be created in working directory, which is used as input file of `game of life`.
2. [runs.sh](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung4/runs.sh)   
With this **.sh** file [run_sim.sh](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung4/run_sim.sh) will be automatically executed. With given value of `frac` the directory `.../frac0.x/config$i` will be created, here`$i` is from 1 to 10.
3. [calc_frac.sh](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung4/calc_frac.sh)   
With specified filename `field$i.dat` where `$i` increases itself in the loop, the **frequency of life** will be calculated in every step of development. Here **frequency of life** is defined as **accupied units / sum of units**. The result of calculation will be written in `result_frac.dat` in working directory.
4. [run_calc_frac.sh](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung4/run_calc_frac.sh)   
Automatically executing `calc_frac.sh`. With given value of `frac` the commands in `calc_frac.sh` will be executed in directory `.../runs/frac0.x/config$i`.
5. [frac_avrg.sh](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung4/frac_avrg.sh)   
With given value of `frac` the data in file named `result_frac.dat` in directory `.../runs/frac0.x/config$i` will be extracted. Then it will calculate the average value of **frequency of life** in every step of development. The result will be written in file `result_frac_avrg.dat`.
### - `game_of_life_loesung` Directory
Source files of `game of life` are deposited there. Detailed information about `game of life` refers to [Uebung 3](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/tree/master/Uebung3)
### - `runs` Directory
1. [plot_frac_evo.gp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung4/runs/plot_frac_evo.gp)   
Using calculation result `result_frac.dat` in directory `.../runs/frac0.x/config$i` to plot the graph.
![image](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung4/runs/frac_evo.png)
2. [plot_frac_avrg.gp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung4/runs/plot_frac_avrg.gp)   
Using calculation result `result_frac_avrg.dat` in directory `.../runs/frac0.x` to plot the graph.
![image](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung4/runs/frac_avrg.png)

## Uebung 3
Using libary [Eigen3](http://eigen.tuxfamily.org/index.php?title=Main_Page).  
Ggenerate a matrix to simulate a 'game of life', ouput data can be plotted with GNUPLOT.
1. [functions_game.h](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung3/functions_game.h)  
Headfile of 'functions_game.cpp'
2. [functions_game.cpp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung3/functions_game.cpp)  
Include 4 operations of a matrix:
  * create_field2d(x, y): generate a matrix of x rows and y columns
  * init_field2s(matrix, frac): randomly arrange the matrix with 0 and 1 where frac = sum(1) / (x * y)
  * make_step(matrix1,matrix2): refresh the state of matrix1 with a temp matrix2
  * plot_field(matrix, n): output the matrix by given interval n
3. [main_game.cpp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung3/main_game.cpp)  
Main function, to start a game of life
4. [Makefile](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung3/Makefile)

## Uebung 2
1. [fibonacci.cpp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung2/fibonacci.cpp)  
Generate fibonacci sequence with the ratio of neighboring number
  * input:
    - count: number of numbers in generated sequence
  * output:
    - fibonacci sequence
    - ratio of neighboring number
2. [MKinteg.cpp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung2/MKinteg.cpp)  
Calculate the area of a circle using Monte Carlo Integration methode
  * Input:
    - r: radius of a circle
  * Outut:
    - area of the circle
    
## Uebung 1
[sinus_plot.cxx](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung1/sinus_plot.cxx)  
Generate a sequence of x and sin(x)

* Input: 
  * (input has beed protected by checking its legality)
  * hw: the times of halfwave length
  * nsteps: number of sampling points

* Output:
  * sequence of x and f(x)
