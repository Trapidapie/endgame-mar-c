#include "../../resource/header.h"

void render_obj(SDL_Renderer* renderer, Object obj) {
    if (obj.bg != NULL) {
        SDL_RenderCopy(renderer, obj.bg, NULL, &obj.position);
    }
}