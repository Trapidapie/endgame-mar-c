#include "../../resource/header.h"

void win_build_Settings(SDL_Renderer* renderer, SDL_Window* window ,SDL_Texture* settingsButtonTextures[], SDL_Texture* backgroundsettings){
    SDL_RenderCopy(renderer, backgroundsettings, NULL, NULL);

    int buttonWidth = 430;
    int buttonHeight = 110;
    int buttonSpacing = 60;
    int startY = 310;
    int startX = 500;

    for (int i = 0; i < 2; ++i)
        render_button(renderer, settingsButtonTextures[i], startX + i * (buttonWidth + buttonSpacing), startY,
                      buttonWidth, buttonHeight);

    buttonWidth = 300;
    buttonHeight = 111;
    buttonSpacing = 50;
    startY = 570;
    startX = 460;
    for (int i = 2; i < 5; ++i)
        render_button(renderer, settingsButtonTextures[i], startX + (i - 2) * (buttonWidth + buttonSpacing), startY,
                      buttonWidth, buttonHeight);

    buttonWidth = 200;
    buttonHeight = 75;
    buttonSpacing = 100;
    startY = 815;
    startX = 720;
    for (int i = 5; i < 7; ++i)
        render_button(renderer, settingsButtonTextures[i], startX + (i - 5) * (buttonWidth + buttonSpacing), startY,
                      buttonWidth, buttonHeight);
    SDL_RenderPresent(renderer);
}