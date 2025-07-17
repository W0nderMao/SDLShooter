#include "SceneMain.h"
#include "Game.h"
#include "SDL.h"
#include "SDL_image.h"

SceneMain::SceneMain() {

}

SceneMain::~SceneMain() {

}

void SceneMain::update_Scene() {

}

void SceneMain::init_Scene() {
    player.texture = IMG_LoadTexture(Game::getInstance().getRender(), "assets/image/SpaceShip.png");
    SDL_QueryTexture(player.texture, NULL, NULL, &player.width, &player.height);//设置player的宽和高，函数的作用是将纹理的长宽填充到最后两个参数中去
    player.height /= 4;
    player.width /= 4;
    player.position.x = Game::getInstance().getWindowWidth() / 2 - player.width / 2;
    player.position.y = Game::getInstance().getWindowHeight() - player.height;
}

void SceneMain::render_Scene() {
    SDL_Rect PLayerRect = {static_cast<int>(player.position.x), static_cast<int>(player.position.y), player.width, player.height};
    SDL_RenderCopy(Game::getInstance().getRender(), player.texture, NULL, &PLayerRect);
}

void SceneMain::clean_Scene() {
    if(player.texture != nullptr)
    {
        SDL_DestroyTexture(player.texture);
    }
}

void SceneMain::handleEvent_Scene(SDL_Event *event) {

}
