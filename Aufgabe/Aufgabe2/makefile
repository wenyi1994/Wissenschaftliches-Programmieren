PROG = convergency

FLAGS = -O2

CC = g++

SRCS = complex.cpp complex_convergency.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC)  $(FLAGS) -c $<

clean:
	rm -rf *.o $(PROG)

## dependencies

complex.o: complex.cpp complex.h

main_complex_beispiel.o: complex_convergency.cpp complex.cpp complex.h 