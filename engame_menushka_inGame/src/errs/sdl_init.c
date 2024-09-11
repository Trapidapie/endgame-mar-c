#include "../../resource/header.h"

void sdl_init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("err init SDL: %s", SDL_GetError());
        exit(1);
    }
}