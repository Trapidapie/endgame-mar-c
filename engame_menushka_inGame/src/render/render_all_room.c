#include "../../resource/header.h"

void render_all_room(SDL_Renderer* renderer, const Board* room, Object* objects, int len_objs) {
    render_bg(renderer, room->bg);
    render_board(renderer, room);

    for (int i = 0; i < len_objs; i++) {
        render_obj(renderer, objects[i]);
    }
}