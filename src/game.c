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
    game->w = 640;
    game->h = 480;
    game->window = SDL_CreateWindow("C Raycaster", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, game->w, game->h, SDL_WINDOW_SHOWN);
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);

    player->x = 3;
    player->y = 2;

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

void getKeyboardInput(void)
{
    while(SDL_PollEvent(&game.event))
    {
        switch(game.event.type)
        {
            case SDL_KEYDOWN:
            {
                switch(game.event.key.keysym.sym)
                {
                    case SDLK_w:
                    {
                        float pCosW = cosf(player.angle) * 0.2f;
                        float pSinW = sinf(player.angle) * 0.2f;
                        player.x += pCosW;
                        player.y += pSinW;
                        break;
                    }  
                    case SDLK_s:
                    {
                        float pCos = cosf(player.angle) * 0.2f;
                        float pSin = sinf(player.angle) * 0.2f;
                        player.x -= pCos;
                        player.y -= pSin;
                        break;
                    }
                    case SDLK_a:
                    {
                        player.angle-=0.10f;
                        if(player.angle < 0.0f) player.angle = 2*PI;
                        break;
                    }
                    case SDLK_d:
                    {
                        player.angle+=0.10f;
                        if(player.angle >= (2*PI)) player.angle = 0.0f;
                        break;
                    }
                }
            }
            /*
            case SDL_MOUSEMOTION:
            {
                int currMousePosX = 0;
                int currMousePosY = 0;
                SDL_GetMouseState(&currMousePosX, &currMousePosY);

                if(currMousePosX - prevMouseX >= 1)
                {
                    player.angle+=0.15f;
                    if(player.angle >= (2*PI)) player.angle = 0.0f;
                }
                else if(prevMouseX > currMousePosX && prevMouseX - currMousePosX >= 1){
                    player.angle-=0.15f;
                    if(player.angle < 0.0f) player.angle = 2*PI;                    
                }
                prevMouseX = currMousePosX;
                break;
            }
            */
        }
    }
}

void render(void)
{
    SDL_RenderSetScale(game.renderer, 1.0f, 1.0f);

    SDL_SetRenderDrawColor(game.renderer, 0,0,0,255);
    SDL_RenderClear(game.renderer);

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

    SDL_RenderPresent(game.renderer);
}