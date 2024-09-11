#include "../../resource/header.h"

bool handle_mouse_button_down(SDL_Event e, int x_min, int x_max, int y_min, int y_max, void (*action)(Mix_Chunk*), Mix_Chunk* soundEffect) {
    if (e.button.button == SDL_BUTTON_LEFT &&
        e.button.x >= x_min && e.button.x <= x_max &&
        e.button.y >= y_min && e.button.y <= y_max) {
        action(soundEffect);
        return true;
    }
    return false;
}