PROG = prog_solver

FLAGS = -O2

CC = g++

SRCS = main_programm_solver.cpp vector_funcs.cpp matrix_funcs.cpp solver_funcs.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC)  $(FLAGS) -c $<

clean:
	rm -rf *.o $(PROG) 

## dependencies

main_programm_solver.o: main_programm_solver.cpp vector_funcs.h matrix_funcs.h solver_funcs.h

vector_funcs.o: vector_funcs.cpp vector_funcs.h

matrix_funcs.o: matrix_funcs.cpp matrix_funcs.h vector_funcs.h

solver_funcs.o: solver_funcs.cpp solver_funcs.h  vector_funcs.h matrix_funcs.h
