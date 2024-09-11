#include "../../resource/header.h"

void update_hero(SDL_Rect* hero, int speed, Board* room, bool* running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *running = false;
        }
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);
    int newX = hero->x, newY = hero->y;

    if (state[SDL_SCANCODE_W]) {
        newY -= speed;
    }
    if (state[SDL_SCANCODE_S]) {
        newY += speed;
    }
    if (state[SDL_SCANCODE_A]) {
        newX -= speed;
    }
    if (state[SDL_SCANCODE_D]) {
        newX += speed;
    }

    SDL_Rect newHeroRect = {newX, newY, hero->w, hero->h};

    // Проверка столкновений с каждой стеной
    if (!check_collision(&newHeroRect, &room->topWall) &&
        !check_collision(&newHeroRect, &room->bottomWall) &&
        !check_collision(&newHeroRect, &room->leftWall) &&
        !check_collision(&newHeroRect, &room->rightWall)) {
        hero->x = newX;
        hero->y = newY;
    }
}