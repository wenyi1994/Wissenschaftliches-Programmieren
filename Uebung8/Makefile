PROG=mdsim

CC=g++
FLAGS=-std=c++11 -O2

SRCS= interaction_lj.cpp  linked_list.cpp     particle_dyn_ll.cpp verlet.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC)  $(FLAGS) -c $<

clean:
	rm -rf $(PROG) *.o

# DO NOT DELETE

interaction_lj.o: interaction_lj.cpp particle.h
linked_list.o: linked_list.cpp particle.h
particle_dyn_ll.o: particle_dyn_ll.cpp particle.h verlet.h linked_list.h interaction_lj.h
verlet.o: verlet.cpp particle.h verlet.h
