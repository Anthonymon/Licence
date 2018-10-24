#!/bin/bash

cible="$1"
source="$1.c"

if [ ! -f "$source" ]; then
	echo "Le fichier \"$source\" n'existe pas. Le nom du fichier doit se terminer par .c"
	exit 1
fi

echo "gcc -g -Wall `sdl-config --cflags` \"$source\" -o \"$cible\" -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf"

gcc -g -Wall `sdl-config --cflags` "$source" -o "$cible" -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf
retour=$?
if [ "$retour" != "0" ]; then
	exit 2
fi

exit 0
