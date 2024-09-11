#include "../../resource/header.h"

void render_bg(SDL_Renderer* renderer, SDL_Texture* texture) {

    SDL_RenderCopy(renderer, texture, NULL, NULL); // Копирование текстуры на весь экран
}