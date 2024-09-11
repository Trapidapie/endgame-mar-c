#include "../../resource/header.h"

void play_sound(Mix_Chunk* sound) {
    int channel = Mix_GroupAvailable(-1);
    Mix_PlayChannel(channel, sound, 0);
}