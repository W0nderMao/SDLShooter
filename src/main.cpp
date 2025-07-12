#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;

    //初始化SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
        return 1;
    }

    //创建窗口
    SDL_Window* window = SDL_CreateWindow("Hello World", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    //创建渲染器
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //图片加载
    //如果需要加载图片，需要初始化IMG库
    if(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != (IMG_INIT_PNG | IMG_INIT_JPG))
    {
        std::cerr << "IMG_Init error: " << IMG_GetError() << std::endl;
        return 1;
    }
    //加载图片
    SDL_Texture* texture = IMG_LoadTexture(renderer, "assets/image/bg.png");

    //音乐初始化
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cerr << "Mix_OpenAudio error: " << Mix_GetError() << std::endl;
        return 1;
    }

    //加载音乐
    Mix_Music* music = Mix_LoadMUS("assets/music/03_Racing_Through_Asteroids_Loop.ogg");
    //播放音乐
    Mix_PlayMusic(music, -1); // -1表示无限循环播放

    //字体初始化
    if(TTF_Init() == -1)
    {
        std::cerr << "TTF_Init error: " << TTF_GetError() << std::endl;
        return 1;
    }
    //加载字体
    TTF_Font* font = TTF_OpenFont("assets/font/VonwaonBitmap-12px.ttf", 24);
    SDL_Surface* Surface = TTF_RenderUTF8_Solid(font, "Hello, SDL!", {255, 255, 255});
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, Surface);

    //渲染循环
    while(true)
    {
        SDL_Event event;
        if(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                break;
            }
        }
        //清除渲染器
        SDL_RenderClear(renderer);
        //长方形
        SDL_Rect rect = { 100, 100, 200, 200 };
        //设置画笔颜色
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        //渲染长方形
        SDL_RenderFillRect(renderer, &rect);
        //重置画笔颜色（重置后的颜色其实就是画布的底色），因为清屏时会用重置后的颜色
        //如果不重置颜色，下一次渲染的颜色会覆盖在上
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        //画图片
        SDL_Rect dstRect = { 200, 200, 300, 400 }; // 设置目标矩形的大小和位置
        SDL_RenderCopy(renderer, texture, NULL, &dstRect); // 渲染纹理到目标矩形

        //画文本
        SDL_Rect textRect = { 300, 300, Surface->w, Surface->h }; // 设置文本矩形的大小和位置
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect); // 渲染

        //显示渲染器内容
        SDL_RenderPresent(renderer);
    }

    //清除字体系统
    SDL_FreeSurface(Surface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();

    //清除音乐系统
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    Mix_Quit();

    //清除图片系统
    SDL_DestroyTexture(texture);
    IMG_Quit();

    //清理并退出系统
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}