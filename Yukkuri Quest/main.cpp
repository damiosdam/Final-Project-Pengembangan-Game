#include "Game.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    Game game;

    game.Init("Yukkuri Quest", screenWidth, screenHeight);

    game.Run();

    game.Clean();

    return 0;
}