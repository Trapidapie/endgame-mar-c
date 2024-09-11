#include "../../resource/header.h"


Object* init_first_room(SDL_Renderer* renderer) {
    char* filenames[] = {
            "../resource/static/non_active/clock.PNG",
            "../resource/static/non_active/cupboard.PNG",
            "../resource/static/non_active/cupboard_books.PNG",
            "../resource/static/non_active/fireplace.PNG",
            "../resource/static/non_active/greenandblue_mushroom.PNG",
            "../resource/static/non_active/picture.PNG",
            "../resource/static/non_active/pudge.PNG",
            "../resource/static/non_active/red_mushroom.PNG",
            "../resource/static/non_active/tumbler.PNG",
            "../resource/static/non_active/win.PNG",
            "../resource/static/non_active/yellow_mushroom.PNG"
    };

    SDL_Rect positions[] = {
            { 270, 110, 140, 140},
            { 230, 550, 240, 360},
            { 450, 140, 300, 400},
            { 1210, 260, 500, 250 },
            { 270, 260, 105, 305 },
            { 1290, 55, 360, 200 },
            { 720, 350, 140, 140},
            { 1280, 600, 400, 400 },
            { 550, 840, 170, 170 },
            { 800, 60, 421, 300},
            { 270, 840, 170, 170 },
    };

    Object* objects = malloc(sizeof(Object) * 11);

    for (int i = 0; i < 11; i++) {
        objects[i].bg = malloc(strlen(filenames[i]) + 1);
        objects[i].bg = load_texture(filenames[i], renderer);
        objects[i].position = positions[i];
    }

    return objects;
}