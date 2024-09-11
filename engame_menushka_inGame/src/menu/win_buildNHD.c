#include "../../resource/header.h"

void win_buildNHD(SDL_Renderer* renderer, SDL_Window* window, SDL_Texture* backgroundTexture[], SDL_Texture* buttonTextures[], SDL_Texture* settingsButtonTextures[], SDL_Texture* authorsBackgroundTexture, Mix_Chunk* clickButton, SDL_Event e, bool inSettingsPage, bool inAuthorsPage){
    if (!inSettingsPage && !inAuthorsPage) {
        SDL_RenderCopy(renderer, backgroundTexture[0], NULL, NULL);
        SDL_RenderCopy(renderer, backgroundTexture[2], NULL, NULL);
        int buttonWidth = 310;
        int buttonHeight = 90;
        int buttonSpacing = 20;
        int startY = 100;

        for (int i = 0; i < 4; ++i) {
            int startX = 60;
            render_button(renderer, buttonTextures[i], startX, startY + i * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight);
        }
        SDL_RenderCopy(renderer, backgroundTexture[1], NULL, NULL);
    }
    else if (inSettingsPage) {
        SDL_RenderCopy(renderer, backgroundTexture[3], NULL, NULL);

        int buttonWidth = 170;
        int buttonHeight = 70;
        int buttonSpacing = 60;
        int startY = 165;
        int startX = 200;

        for (int i = 0; i < 2; ++i)
            render_button(renderer, settingsButtonTextures[i], startX + i * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight);

        if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 200 && e.button.x <= 370 && e.button.y >= 165 && e.button.y <= 235) {
            play_sound(clickButton);
            SDL_SetWindowFullscreen(window, 0);
        }
        else if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 430 && e.button.x <= 600 && e.button.y >= 165 && e.button.y <= 235) {
            play_sound(clickButton);
            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
        }
        buttonWidth = 120;
        buttonHeight = 65;
        buttonSpacing = 30;
        startY = 315;
        startX = 190;
        for (int i = 2; i < 5; ++i)
            render_button(renderer, settingsButtonTextures[i], startX + (i - 2) * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight);
        buttonWidth = 90;
        buttonHeight = 40;
        buttonSpacing = 50;
        startY = 455;
        startX = 300;
        for (int i = 5; i < 7; ++i)
            render_button(renderer, settingsButtonTextures[i], startX + (i - 5) * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight);
    }
    else if (inAuthorsPage)
        SDL_RenderCopy(renderer, authorsBackgroundTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
}