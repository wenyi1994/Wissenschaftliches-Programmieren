#!/bin/bash


NX=100
NY=100

frac=$1

echo $1

MAXSTEP=100
NWRITE=1

{
    echo $NX $NY
    echo $frac
    echo $MAXSTEP
    echo $NWRITE
} > "conf_start"

/home/yi/Documents/Uebung4/game_of_life_loesung/game_of_life/game < conf_start
