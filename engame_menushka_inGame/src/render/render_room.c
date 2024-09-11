#include "header.h"

Board render_board(SDL_Renderer* renderer, const Board* board) {
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

//    render_bg(renderer, room->bg);
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0); // Красный цвет для стен
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 222);

    SDL_RenderFillRect(renderer, &board->topWall);
    SDL_RenderFillRect(renderer, &board->bottomWall);
    SDL_RenderFillRect(renderer, &board->leftWall);
    SDL_RenderFillRect(renderer, &board->rightWall);
}