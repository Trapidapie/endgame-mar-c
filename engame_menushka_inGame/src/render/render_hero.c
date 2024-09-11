#include "../../resource/header.h"

void render_hero(SDL_Renderer* renderer, SDL_Rect* hero, SDL_Texture* heroTexture) {

    if (!heroTexture) {
        printf("Ошибка загрузки текстуры героя: %s\n", SDL_GetError());
        return;
    }

    // Отрисовка героя
    SDL_RenderCopy(renderer, heroTexture, NULL, hero);

    // Отображение отрисованного кадра
    SDL_RenderPresent(renderer);
}
