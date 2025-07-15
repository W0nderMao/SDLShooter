#ifndef SDLSHOOTER_SCENEMAIN_H
#define SDLSHOOTER_SCENEMAIN_H

#include "Scene.h"
#include "SDL.h"
class SceneMain : public Scene
{
    public :
        SceneMain();
        ~SceneMain();

        void update() override;
        void init() override;
        void render() override;
        void clean() override;
        void handleEvent(SDL_Event* event) override;
};



#endif //SDLSHOOTER_SCENEMAIN_H
