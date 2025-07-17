#include "Game.h"
#include "SDL.h"
#include "SceneMain.h"
#include "SDL_image.h"

Game::Game()
{
}

Game::~Game()
{
    clean_Game();
}

void Game::run_Game() {
    while(isRunning)
    {
        SDL_Event event;
        handleEvent_Game(&event);//事件处理

        update_Game();//逻辑更新

        render_Game();//渲染器
    }
}

void Game::init_Game() {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)//初始化SDL2
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL could not init! SDL_Error: %s/n", SDL_GetError());
        isRunning = false;
    }
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);//初始化窗口
    if(window == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Window could not be created! SDL_Error: %s/n", SDL_GetError());
        isRunning = false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);//初始化渲染器
    if(renderer == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Renderer could not be created! SDL_Error: %s/n", SDL_GetError());
        isRunning = false;
    }

    if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_image could not init! SDL_Error: %s/n", SDL_GetError());
        isRunning = false;
    }

    currentScene = new SceneMain();
    currentScene->init_Scene();
}

void Game::clean_Game() {
    //清除操作
    if(currentScene != nullptr)
    {
        currentScene->clean_Scene();
        delete currentScene;
    }

    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::changeScene(Scene *scene)
{
    if(currentScene != nullptr)
    {
        currentScene->clean_Scene();
        delete currentScene;
    }
    currentScene = scene;
    currentScene->init_Scene();
}

void Game::update_Game()
{
    currentScene->update_Scene();
}

void Game::render_Game()
{
    SDL_RenderClear(renderer);//清空
    currentScene->render_Scene();//渲染
    SDL_RenderPresent(renderer);//显示
}

void Game::handleEvent_Game(SDL_Event *event)
{
    while (SDL_PollEvent(event))
    {
        if (event->type == SDL_QUIT)
        {
            isRunning = false;
        }
        currentScene->handleEvent_Scene(event);
    }
}