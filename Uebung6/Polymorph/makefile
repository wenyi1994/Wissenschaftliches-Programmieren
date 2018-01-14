PROG = polymorph

FLAGS = -O2

CC = g++ --std=c++11

SRCS = polymorph.cpp polymorph_funcs.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC)  $(FLAGS) -c $<
	
clean:
	rm -rf *.o $(PROG)

## dependencies

polymorph_funcs.o: polymorph_funcs.cpp polymorph_funcs.h
polymorph.o: polymorph.cpp polymorph_funcs.h


