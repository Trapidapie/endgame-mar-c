#include "../../resource/header.h"

SDL_Window* sdl_window() {
    SDL_Window *window = SDL_CreateWindow("2D Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
    if (!window) {
        SDL_Log("err create win: %s", SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    return window;
}