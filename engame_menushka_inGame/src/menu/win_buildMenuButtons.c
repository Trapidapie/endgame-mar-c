#include "../resource/header.h"
void win_buildMenuButtons(SDL_Renderer* renderer, SDL_Texture* menuButtonTexture[]) {
    SDL_Rect buttonRect;
    buttonRect.w = 600;
    buttonRect.h = 150;
    for (int i = 0; i < 3; ++i) {
        buttonRect.x = 680;
        buttonRect.y = 300 + i * 200;
        SDL_RenderCopy(renderer, menuButtonTexture[i], NULL, &buttonRect);
    }
    SDL_RenderPresent(renderer);
}