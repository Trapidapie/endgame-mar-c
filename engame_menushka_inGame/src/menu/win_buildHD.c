#include "../../resource/header.h"

void win_buildHD(SDL_Renderer* renderer, SDL_Window* window, SDL_Texture* backgroundTexture[], SDL_Texture* buttonTextures[], SDL_Texture* settingsButtonTextures[], SDL_Texture* authorsBackgroundTexture, Mix_Chunk* clickButton, SDL_Event e, bool inSettingsPage, bool inAuthorsPage){
    if (!inSettingsPage && !inAuthorsPage) {
        SDL_RenderCopy(renderer, backgroundTexture[0], NULL, NULL);
        SDL_RenderCopy(renderer, backgroundTexture[2], NULL, NULL);
        int buttonWidth = 450;
        int buttonHeight = 110;
        int buttonSpacing = 20;
        int startY = 140;

        for (int i = 0; i < 4; ++i) {
            int startX = 50;
            render_button(renderer, buttonTextures[i], startX, startY + i * (buttonHeight + buttonSpacing), buttonWidth,
                          buttonHeight);
        }
        SDL_RenderCopy(renderer, backgroundTexture[1], NULL, NULL);
    } else if (inSettingsPage) {
        SDL_RenderCopy(renderer, backgroundTexture[3], NULL, NULL);

        int buttonWidth = 300;
        int buttonHeight = 75;
        int buttonSpacing = 10;
        int startY = 210;
        int startX = 340;

        for (int i = 0; i < 2; ++i)
            render_button(renderer, settingsButtonTextures[i], startX + i * (buttonWidth + buttonSpacing), startY,
                          buttonWidth, buttonHeight);

        if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 340 && e.button.x <= 640 &&
            e.button.y >= 210 && e.button.y <= 285) {
            play_sound(clickButton);
            SDL_SetWindowFullscreen(window, 0);
        } else if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 650 && e.button.x <= 950 &&
                   e.button.y >= 210 && e.button.y <= 285) {
            play_sound(clickButton);
            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
        }
        buttonWidth = 200;
        buttonHeight = 75;
        buttonSpacing = 50;
        startY = 380;
        startX = 290;
        for (int i = 2; i < 5; ++i)
            render_button(renderer, settingsButtonTextures[i], startX + (i - 2) * (buttonWidth + buttonSpacing), startY,
                          buttonWidth, buttonHeight);
        buttonWidth = 135;
        buttonHeight = 55;
        buttonSpacing = 50;
        startY = 540;
        startX = 510;
        for (int i = 5; i < 7; ++i)
            render_button(renderer, settingsButtonTextures[i], startX + (i - 5) * (buttonWidth + buttonSpacing), startY,
                          buttonWidth, buttonHeight);
    } else if (inAuthorsPage)
        SDL_RenderCopy(renderer, authorsBackgroundTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
}