#include "game.h"

int map[8][8] = 
{
    {1,2,3,4,1,2,3,4},
    {4,0,0,0,0,0,0,1},
    {3,0,2,2,2,0,0,2},
    {1,0,0,0,2,0,0,2},
    {2,0,0,0,2,0,0,2},
    {1,0,0,0,1,1,1,1},
    {3,0,0,0,0,0,0,1},
    {3,2,1,2,1,1,1,1},
};

void initGame(Game* game, Player* player)
{
    game->running = true;
    game->w = 640;
    game->h = 480;
    game->window = SDL_CreateWindow("C Raycaster", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, game->w, game->h, SDL_WINDOW_SHOWN);
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);

    player->x = 2.0f;
    player->y = 2.0f;

    player->fov = PI / 3;
    player->angle = PI;
}

void checkPlayerBoundaries(void)
{
    if(player.x > 8 || player.x < 0 || player.y > 8 || player.y < 0)
    {
        player.x = player.y = 5;
    }
}

void render(void)
{
    SDL_RenderSetScale(game.renderer, 1.0f, 1.0f);

    SDL_SetRenderDrawColor(game.renderer, 0,0,0,255);
    SDL_RenderClear(game.renderer);

    raycast();

    SDL_RenderPresent(game.renderer);
}

void quitGame(Game* game)
{
    SDL_DestroyWindow(game->window);
    SDL_DestroyRenderer(game->renderer);
    SDL_Quit();
}