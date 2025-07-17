#pragma once

#include "Scene.h"
#include "SDL.h"

class Game
{
    public:
        static Game& getInstance()
        {
            static Game Instance;
            return Instance;
        };
        ~Game();
        void run_Game();
        void init_Game();
        void clean_Game();
        void changeScene(Scene* scene);

        void update_Game();
        void render_Game();
        void handleEvent_Game(SDL_Event* event);

        SDL_Renderer* getRender() {return renderer;}
        SDL_Window* getWindow() {return window;}
        int getWindowWidth() {return windowWidth;}
        int getWindowHeight() {return windowHeight;}
    private:
        Game();
        //删除拷贝和赋值构造函数
        Game(const Game&) = delete;
        Game& operator = (const Game&) = delete;
        bool isRunning = true;
        Scene* currentScene = nullptr;
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        int windowWidth = 600;
        int windowHeight = 800;
};