#pragma once

#include "SDL.h"

class Scene
{
    public:
        Scene() = default;
        virtual ~Scene() = default;
        virtual void init_Scene() = 0;
        virtual void update_Scene() = 0;
        virtual void render_Scene() = 0;
        virtual void clean_Scene() = 0;
        virtual void handleEvent_Scene(SDL_Event* event) = 0;
};