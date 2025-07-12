#pragma once

class Game
{
    public:
        Game();
        ~Game();
        void run();
        void init();
        void clean();
    private:
    bool isRunning = true;


};