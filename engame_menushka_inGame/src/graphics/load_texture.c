#include "../../resource/header.h"

SDL_Texture* load_texture(const char* filename, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(filename);
    if (!surface) {
        printf("eer dwnld img: %s\n", IMG_GetError());
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        printf("err texture: %s\n", SDL_GetError());
    }
    return texture;
}
