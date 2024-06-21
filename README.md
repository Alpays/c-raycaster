# C Raycaster Application
This is a raycaster program written in C with SDL graphics library. \
This tutorial made me understand how Raycasting rendering works as well as fish eye fix.
https://github.com/vinibiavatti1/RayCastingTutorial/wiki/RayCasting 

# Compiling

This program can be compiled with gcc compiler with the following code; 

gcc -L lib -o main -o game main.c game.c raycast.c input.c -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -mwindows

# What more can be added

* Textures 
* Floor/Background casting 
* Shooting mechanic 
* Enemies
