#include "raycast.h"

void raycast(void)
{
    // Raycasting Calculations and Rendering the world goes here.
    
    float rayAngle = player.angle - (player.fov / 2);

    for(int i = 0; i < game.w; ++i)
    {
        float rayX = player.x;
        float rayY = player.y;

        int wallFound = 0;

        while(!wallFound)
        {
            rayX += cosf(rayAngle) / 64.0f;
            rayY += sinf(rayAngle) / 64.0f;

            wallFound = map[(int)rayY][(int)rayX];
        }

        float dist = sqrt(pow(player.x - rayX, 2) + pow((player.y - rayY), 2));

        dist = dist*cosf(rayAngle - player.angle); // Fix fisheye view.

        int wHeight = (int)floor((game.h / 2) / dist);

        SDL_SetRenderDrawColor(game.renderer, 0,0,255,255);
        SDL_RenderDrawLine(game.renderer, i, (game.h) - wHeight, i, 0);
        switch(wallFound)
        {
            case 1:
                SDL_SetRenderDrawColor(game.renderer, 255,0,0,255);
                break;
            case 2: 
                SDL_SetRenderDrawColor(game.renderer, 255,255,0,255);
                break;
            case 3:
                SDL_SetRenderDrawColor(game.renderer, 255,255,255,255);
                break;
            case 4:
                SDL_SetRenderDrawColor(game.renderer, 0,0,0,255);
        }
        SDL_RenderDrawLine(game.renderer, i, (game.h / 2) + wHeight, i, (game.h / 2) - wHeight);
        SDL_SetRenderDrawColor(game.renderer, 0, 255, 0, 255);
        SDL_RenderDrawLine(game.renderer, i, (game.h / 2) + wHeight, i, game.h);

        rayAngle += ((player.fov) / game.w);
    }
}