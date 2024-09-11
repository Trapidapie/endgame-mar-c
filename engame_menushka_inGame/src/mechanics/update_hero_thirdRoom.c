#include "../../resource/header.h"

void update_hero_thirdRoom(SDL_Rect* hero, int speed, Board* room, bool* running) {
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
    bool collided_with_wall = false;
    if (check_collision(&newHeroRect, &room->wall1) || check_collision(&newHeroRect, &room->wall2) ||
        check_collision(&newHeroRect, &room->wall3) || check_collision(&newHeroRect, &room->wall4) ||
        check_collision(&newHeroRect, &room->wall5) || check_collision(&newHeroRect, &room->wall6) ||
        check_collision(&newHeroRect, &room->wall7) || check_collision(&newHeroRect, &room->wall8) ||
        check_collision(&newHeroRect, &room->wall9) || check_collision(&newHeroRect, &room->wall10) ||
        check_collision(&newHeroRect, &room->wall11) || check_collision(&newHeroRect, &room->wall12) ||
        check_collision(&newHeroRect, &room->wall13) || check_collision(&newHeroRect, &room->wall14)) {
        collided_with_wall = true;
    }

    if (!collided_with_wall) {
        hero->x = newX;
        hero->y = newY;
    } else {
        // Если произошло столкновение, возвращаем героя в начальное положение
        hero->x = 1400;
        hero->y = 910;
    }
}