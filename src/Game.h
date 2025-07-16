#pragma once

#include "Scene.h"
#include "SDL.h"

class Game
{
    public:
        Game();
        ~Game();
        void run_Game();
        void init_Game();
        void clean_Game();
        void changeScene(Scene* scene);

        void update_Game();
        void render_Game();
        void handleEvent_Game(SDL_Event* event);
    private:
        bool isRunning = true;
        Scene* currentScene = nullptr;
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        int windowWidth = 600;
        int windowHeight = 800;
};