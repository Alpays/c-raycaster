#include "input.h"

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
                break;
            }
            case SDL_QUIT:
                game.running = false;
                break;
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