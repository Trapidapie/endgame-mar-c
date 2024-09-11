#include "header.h"

Board render_board_thirdRoom(SDL_Renderer* renderer, const Board* board) {
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 222);

    SDL_RenderFillRect(renderer, &board->wall1);
    SDL_RenderFillRect(renderer, &board->wall2);
    SDL_RenderFillRect(renderer, &board->wall3);
    SDL_RenderFillRect(renderer, &board->wall4);
    SDL_RenderFillRect(renderer, &board->wall5);
    SDL_RenderFillRect(renderer, &board->wall6);
    SDL_RenderFillRect(renderer, &board->wall7);
    SDL_RenderFillRect(renderer, &board->wall8);
    SDL_RenderFillRect(renderer, &board->wall9);
    SDL_RenderFillRect(renderer, &board->wall10);
    SDL_RenderFillRect(renderer, &board->wall11);
    SDL_RenderFillRect(renderer, &board->wall12);
    SDL_RenderFillRect(renderer, &board->wall13);
    SDL_RenderFillRect(renderer, &board->wall14);
}