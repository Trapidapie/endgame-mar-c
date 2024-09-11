#include "../../resource/header.h"

void render_button(SDL_Renderer* renderer, SDL_Texture* buttonTexture, int x, int y, int w, int h) {
    SDL_Rect buttonRect = { x, y, w, h };
    SDL_RenderCopy(renderer, buttonTexture, NULL, &buttonRect);
}