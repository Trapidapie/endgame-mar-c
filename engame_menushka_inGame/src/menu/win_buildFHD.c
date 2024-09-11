#include "../../resource/header.h"

void win_buildFHD(SDL_Renderer* renderer, SDL_Window* window, SDL_Texture* backgroundTexture[], SDL_Texture* buttonTextures[], SDL_Texture* settingsButtonTextures[], SDL_Texture* authorsBackgroundTexture, Mix_Chunk* clickButton, SDL_Event e, bool inSettingsPage, bool inAuthorsPage) {
    if (!inSettingsPage && !inAuthorsPage) {
        SDL_RenderCopy(renderer, backgroundTexture[0], NULL, NULL);
        SDL_RenderCopy(renderer, backgroundTexture[2], NULL, NULL);
        int buttonWidth = 700;
        int buttonHeight = 160;
        int buttonSpacing = 20;
        int startY = 210;

        for (int i = 0; i < 4; ++i) {
            int startX = 100;
            render_button(renderer, buttonTextures[i], startX, startY + i * (buttonHeight + buttonSpacing), buttonWidth,
                          buttonHeight);
        }
        SDL_RenderCopy(renderer, backgroundTexture[1], NULL, NULL);
    } else if (inSettingsPage) {
        SDL_RenderCopy(renderer, backgroundTexture[3], NULL, NULL);

        int buttonWidth = 430;
        int buttonHeight = 110;
        int buttonSpacing = 60;
        int startY = 310;
        int startX = 500;

        for (int i = 0; i < 2; ++i)
            render_button(renderer, settingsButtonTextures[i], startX + i * (buttonWidth + buttonSpacing), startY,
                          buttonWidth, buttonHeight);

        if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 500 && e.button.x <= 930 &&
            e.button.y >= 310 && e.button.y <= 420) {
            play_sound(clickButton);
            SDL_SetWindowFullscreen(window, 0);
        } else if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 990 && e.button.x <= 1420 &&
                   e.button.y >= 310 && e.button.y <= 420) {
            play_sound(clickButton);
            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
        }
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
    } else if (inAuthorsPage)
        SDL_RenderCopy(renderer, authorsBackgroundTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
}