#pragma once

#include "Scene.h"
#include "SDL.h"

class Game
{
    public:
        Game();
        ~Game();
        void run();
        void init();
        void clean();
        void changeScene(Scene* scene);
    private:
        bool isRunning = true;
        Scene* currentScene = nullptr;
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
};