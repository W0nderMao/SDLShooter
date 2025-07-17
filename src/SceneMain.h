#ifndef SDLSHOOTER_SCENEMAIN_H
#define SDLSHOOTER_SCENEMAIN_H

#include "Scene.h"
#include "SDL.h"
#include "Object.h"
class SceneMain : public Scene
{
    public :
        SceneMain();
        ~SceneMain();

        void update_Scene() override;
        void init_Scene() override;
        void render_Scene() override;
        void clean_Scene() override;
        void handleEvent_Scene(SDL_Event* event) override;
    private:
    Player player;

};



#endif //SDLSHOOTER_SCENEMAIN_H
