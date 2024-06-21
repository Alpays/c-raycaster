#pragma once

#define SDL_MAIN_HANDLED

#include "SDL2/SDL.h"
#include <math.h>
#include <stdbool.h>

#include "input.h"
#include "raycast.h"

#define PI 3.14159

typedef struct
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    int w;
    int h;

    bool running;
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

int map[8][8];

// game functions.

void initGame(Game* game, Player* player);
void checkPlayerBoundaries(void);
void getKeyboardInput(void);
void render(void);
void quitGame(Game* game);
