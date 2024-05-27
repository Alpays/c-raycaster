#include "game.h"

Game game;
Player player;

int main(void)
{
    srand(time(NULL));
    SDL_Init(SDL_INIT_EVERYTHING);

    initGame(&game, &player);

    while(1)
    {
        render();
        getKeyboardInput();
        checkPlayerBoundaries();
    }

    return 0;
}