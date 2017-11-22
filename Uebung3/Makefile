PROG = game

FLAGS = -O2 -I /home/yi/include/ #hier muss der Pfad angepasst werden

CC = g++

SRCS = main_game.cpp functions_game.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC)  $(FLAGS) -c $<

clean:
	rm -rf *.o *.dat $(PROG)

## dependencies

functions_game.o: functions_game.cpp functions_game.h

main_game.o: main_game.cpp functions_game.h   # Quelldatei  und eingebundene Kopfdatei

