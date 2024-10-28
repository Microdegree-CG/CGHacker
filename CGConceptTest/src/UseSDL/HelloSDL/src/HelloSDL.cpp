#include <SDL_error.h>
#include <SDL.h>
#include <cstdio>
#include <iostream>

int main(int argc, char *argv[])
{
    constexpr int width = 640;
    constexpr int height = 480;
    SDL_Window *window = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initizlized: " << SDL_GetError();
    }
    else
    {
        std::cout << "SDL video system is ready to go\n ";
    }
    window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
                              SDL_WINDOW_SHOWN);

    SDL_Delay(3000);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
