#include "game.h"

Game game;
Player player;

int main(void)
{
    srand(time(NULL));
    SDL_Init(SDL_INIT_EVERYTHING);

    initGame(&game, &player);

    Uint64 startTime = SDL_GetTicks64();
    uint32_t frameTime;
    float fps;
    while(game.running)
    {
        render();
        getKeyboardInput();
        checkPlayerBoundaries();
    }

    quitGame(&game);

    return 0;
}