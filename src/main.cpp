#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Game.h"

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;

    Game game;
    game.init_Game();
    game.run_Game();

    return 0;
}