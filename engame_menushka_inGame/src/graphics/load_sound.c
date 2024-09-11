#include "../../resource/header.h"

Mix_Chunk* load_sound(const char* path) {
    Mix_Chunk* sound = Mix_LoadWAV(path);
    return sound;
}
