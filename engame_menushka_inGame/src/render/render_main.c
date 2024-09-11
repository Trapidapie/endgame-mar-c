#include "../../resource/header.h"

void render_main(SDL_Renderer* renderer, SDL_Rect* hero, Board* room, Object* objects, int len_objs) {
    SDL_Texture* mainHeroTexture = IMG_LoadTexture(renderer, "../resource/static/ghost1.PNG");
    // Очистка экрана
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Черный фон
    SDL_RenderClear(renderer);

    // Рендеринг комнаты
    if (room != NULL) {
        render_all_room(renderer, room, objects, len_objs);
    }

    // Рендеринг героя
    if (hero != NULL) {
        render_hero(renderer, hero, mainHeroTexture);
    }



    // Другие элементы рендеринга могут быть добавлены здесь

    SDL_RenderPresent(renderer);
}