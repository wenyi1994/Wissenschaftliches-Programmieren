PROG = vec_mat_test

FLAGS = -O2

CC = g++

SRCS = vector_funcs.cpp matrix_funcs.cpp vec_mat_test.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC)  $(FLAGS) -c $<

clean:
	rm -rf *.o $(PROG)

## dependencies

vector_funcs.o: vector_funcs.cpp vector_funcs.h matrix_funcs.h

matrix_funcs.o: matrix_funcs.cpp matrix_funcs.h

vec_mat_test.o: vec_mat_test.cpp vector_funcs.h matrix_funcs.h