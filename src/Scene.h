#pragma once

class Scene
{
    public:
        Scene() = default;
        virtual ~Scene() = default;
        virtual void init() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void clean() = 0;
        virtual void handleEvents() = 0;
    protected:
        bool isActive = true;
};