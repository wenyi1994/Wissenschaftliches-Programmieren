# Wissenschaftliches-Programmieren `2018/01/16`
Arbeitsbereich fuer Vorlesung: Wissenschaftliches Programmieren fuer Ingenieure in KIT
### `ATTENTION`After download please reset the path in `.sh` `include` or any other file

## Uebung 6
> **Update 2018/01/16**  
> File: [LGS.cpp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung6/LGS/LGS.cpp)  
> Description: Add 2 solving methods for [2. system of linear equation](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/tree/master/Uebung6/LGS): Cholesky Decomposition and Gauss-Seidel Iteration.
1. [Polymorphism](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/tree/master/Uebung6/Polymorph)  
With virtual function some members of function can be declared in base class and in inheritance class will be defined. After keyword `virtual` a virtual member funciton is declared. Pure virtual function can be specified with suffix `=0`, it means this function **MUST** be overrided in subclass.
2. [System of linear equations (auf Deutsch LGS - Linear Gleichungen System)](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/tree/master/Uebung6/LGS)  
The physical model is a spring grid, which is composed by several totally same spring. Given that a externe force will be exert perpendicular to the grid plane, the displacement of each node is requested.  
This question can be solved by matrix that describes the equation system. In this programme LU-decomposition method is applied.  
For instance, suppose a grid consists of `50 x 50` springs, on each node of the grid a force of -3 N is exert (-3 means perpendicular and point to bottom). The displacement of the grid can be described with following contour.  
![image](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung6/LGS/Figure_50_-3_all.jpg)  
> Using [20180114_121253_Eingabe.dat](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung6/LGS/20180114_121253_Eingabe.dat) as input and [20180114_121253_Ausgabe.dat](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung6/LGS/20180114_121253_Ausgabe.dat) is output.
3. [Molecular Dynamics](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/tree/master/Uebung6/Planeten)  
Using Euler-Method or Verlet-Method to study the movement of planet in the field of molecular dynamics. With the passage of time the position and velocity of Planet can be calculated discrete. Further more the energy of celestial body (including kinetic energy and potential energy) can be gotten and it meets the law of conservation.  

*The Trajectory of planet*  
![image](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung6/Planeten/Figure_300_0.jpg)  
> Using [planet.dat](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung6/Planeten/planet.dat) as input and [verlet.dat](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung6/Planeten/verlet.dat) is output.  

*Energy of planet*  
![image](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung6/Planeten/Figure_300_0_en.jpg)

## Aufgabe
> **Update 2017/12/20**  
> File: [complex.cpp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Aufgabe/Aufgabe1/complex.cpp)  
> Describtion: Re-define overloaded operator `^`  

### 1. Rechnen mit komplexen Zahlen
1. [complex.h](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Aufgabe/Aufgabe1/complex.h) | [complex.cpp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Aufgabe/Aufgabe1/complex.cpp)  
Define a class with name `MyComplex`, which can execute complex number calculation. Some operators (`+` `-` `*` `/` `^`) are overloaded when calculated with an other complex number or real number (either on the left side or right side).
2. [main_complex_beispiel.cpp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Aufgabe/Aufgabe1/main_complex_beispiel.cpp)  
To check the correctness of `MyComplex` class, a test programm [main_complex_beispiel.cpp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Aufgabe/Aufgabe1/main_complex_beispiel.cpp) is provided.
3. [makefile](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Aufgabe/Aufgabe1/makefile)

### 2. Untersuchung der Konvergenz komplexer Zahlenfolgen
[complex.h](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Aufgabe/Aufgabe1/complex.h) is imported above.
1. [complex_convergency.cpp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Aufgabe/Aufgabe2/complex_convergency.cpp) is the main programm, which can calculate the convergency radius of a complex and write data in corresponding file. Files with name `start*.dat` can be used as standard input.
2. [runs.sh](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Aufgabe/Aufgabe2/runs.sh) can run this programm automatically, as well as `GNUPLOT` commands defined in [plot.gp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Aufgabe/Aufgabe2/plot.gp) which can plot and ouput image file.
```shell
# execute GNUPLOT commands in shell
echo "
    load 'plot.gp'
    " | gnuplot
```
3. [makefile](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Aufgabe/Aufgabe2/makefile)

## Uebung 5
Pointer und Felder;  
Klassen;  
Lineare Gleichungssysteme, Anwendung: dasWärmeleitproblem.

1. [Assert_test.cpp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung5/Assert_test.cpp)  
Using `assert(condition)` to stop running if `condition` is `false`.  
If the programm should be compiled ignoring `assert()`, use: `g++ -DNDEBUG [file.name]`
2. [Dynamische_Feld.cpp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung5/Dynamische_Feld.cpp)  
Using follwing codes to dynamically create a 2-dimensional-array (3 x 5):
```c++
 // create
 int **b;   
 b = new int*[3];  
 b[0] = new int[3*5];  
 for(int i = 1; i<3; i++)  
 {  
   b[i] = b[0] + i * 5;  
 }
 
 // deconstruct
 delete[] b[0];
 delete[] b;
```
3. [vec_mat](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/tree/master/Uebung5/vec_mat)  
Here are two classes: `Vector` and `Matrix`, some operators are overloaded (such as `=` `+` `*` `()`) to support logical calculation.
4. [solver](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/tree/master/Uebung5/solver)  
This is a solver to linear differential equation. Two methodes of solving are definiert: LU(Lower-Upper)-Decomposition and CG(Conjugate Gradient) in [solver_funcs.cpp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung5/solver/solver_funcs.cpp).  
The physical model of a Heat Transfer problem is shown below:
![image](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung5/solver/physical_model.png)
In [main_programm_solver.cpp](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung5/solver/main_programm_solver.cpp) Gauss-Seidel methode is used to solve the problem.

## Uebung 4
> **Update 2017/11/28**  
> File: [Uebung4/runs.sh](https://github.com/wenyi1994/Wissenschaftliches-Programmieren/blob/master/Uebung4/runs.sh)  
> Describe: The directory of `runs/frac0.x` can be automatically created now.

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
