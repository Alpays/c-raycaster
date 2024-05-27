#ifndef GAME_H
#define GAME_H

#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include <math.h>

#define PI 3.14159

typedef struct
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    int w;
    int h;
} Game;

typedef struct
{
    float x;
    float y;
    float angle;
    float fov;
} Player;

Game game;
Player player;

// game functions.

void initGame(Game* game, Player* player);
void checkPlayerBoundaries(void);
void getKeyboardInput(void);
void render(void);

#endif