#include "../../resource/header.h"

int menu() {
    sdl_init();
    SDL_Window* window = sdl_window();
    SDL_Renderer* renderer = sdl_render(window);

    SDL_Texture* backgroundTexture[4];
    SDL_Texture* authorsBackgroundTexture;
    SDL_Texture* buttonTextures[4];
    SDL_Texture* settingsButtonTextures[7];

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    init_texture_menu(renderer, backgroundTexture, &authorsBackgroundTexture, buttonTextures, settingsButtonTextures);

    Mix_Chunk* clickButton = load_sound("../menu/volume/clickbutton.wav");
    Mix_Music* backgroundVolume = Mix_LoadMUS("../menu/volume/backgroundVolume.wav");

    Mix_PlayMusic(backgroundVolume, -1);

    SDL_Event e;

    bool SetWindowSize1280x720 = false;
    bool SetWindowSize800x600 = false;
    bool SetWindowSize1920x1080 = true;

    bool inSettingsPage = false;
    bool inAuthorsPage = false;
    bool quit = false;


    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {

            bool isPaused = false;
            if (e.type == SDL_QUIT)
                quit = true;

            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (SetWindowSize1920x1080 && !SetWindowSize1280x720 && !SetWindowSize800x600) {

                    if (!inSettingsPage && !inAuthorsPage) {
                        if (handle_mouse_button_down(e, 100, 800, 210, 370, play_sound, clickButton)) {
                            play_sound(clickButton);
                            Mix_PauseMusic();
                            start_game(window, renderer);
                        }
                        if (handle_mouse_button_down(e, 100, 800, 390, 550, play_sound, clickButton)) {
                            inSettingsPage = true;
                        }
                        inAuthorsPage = handle_mouse_button_down(e, 100, 800, 570, 730, play_sound, clickButton) ? true
                                                                                                                 : inAuthorsPage;
                        quit = handle_mouse_button_down(e, 100, 800, 750, 910, play_sound, clickButton) ? true : quit;
                    }

                    if (inSettingsPage) {
                        if (handle_mouse_button_down(e, 450, 760, 570, 681, play_sound, clickButton)) {
                            SDL_SetWindowSize(window, 800, 600);
                            SetWindowSize1920x1080 = false;
                            SetWindowSize800x600 = true;
                            SetWindowSize1280x720 = false;
                        }
                        if (handle_mouse_button_down(e, 810, 1120, 570, 681, play_sound, clickButton)) {
                            SDL_SetWindowSize(window, 1280, 720);
                            SetWindowSize1920x1080 = false;
                            SetWindowSize800x600 = false;
                            SetWindowSize1280x720 = true;
                        }
                        if (handle_mouse_button_down(e, 1170, 1470, 570, 681, play_sound, clickButton)) {
                            SDL_SetWindowSize(window, 1920, 1080);
                            SetWindowSize1920x1080 = true;
                            SetWindowSize800x600 = false;
                            SetWindowSize1280x720 = false;
                        }

                        if (handle_mouse_button_down(e, 720, 920, 815, 890, play_sound, clickButton)) {
                            Mix_PauseMusic();
                            isPaused = true;
                        }
                        if (handle_mouse_button_down(e, 1020, 1220, 815, 890, play_sound, clickButton)) {
                            Mix_ResumeMusic();
                            isPaused = false;
                        }
                    }
                }
                else if (!SetWindowSize1920x1080 && SetWindowSize1280x720 && !SetWindowSize800x600) {
                    if (!inSettingsPage && !inAuthorsPage) {
                        handle_mouse_button_down(e, 50, 500, 140, 250, play_sound, clickButton);
                        inSettingsPage = handle_mouse_button_down(e, 50, 500, 270, 380, play_sound, clickButton) ? true
                                                                                                                 : inSettingsPage;
                        inAuthorsPage = handle_mouse_button_down(e, 50, 500, 400, 510, play_sound, clickButton) ? true
                                                                                                                : inAuthorsPage;
                        quit = handle_mouse_button_down(e, 50, 500, 530, 640, play_sound, clickButton) ? true : quit;
                    }
                    if (inSettingsPage) {
                        if (handle_mouse_button_down(e, 290, 490, 380, 455, play_sound, clickButton)) {
                            SDL_SetWindowSize(window, 800, 600);
                            SetWindowSize1920x1080 = false;
                            SetWindowSize800x600 = true;
                            SetWindowSize1280x720 = false;
                        }
                        if (handle_mouse_button_down(e, 540, 740, 380, 455, play_sound, clickButton)) {
                            play_sound(clickButton);
                            SDL_SetWindowSize(window, 1280, 720);
                            SetWindowSize1920x1080 = false;
                            SetWindowSize800x600 = false;
                            SetWindowSize1280x720 = true;
                        }
                        if (handle_mouse_button_down(e, 790, 990, 380, 455, play_sound, clickButton)) {
                            play_sound(clickButton);
                            SDL_SetWindowSize(window, 1920, 1080);
                            SetWindowSize1920x1080 = true;
                            SetWindowSize800x600 = false;
                            SetWindowSize1280x720 = false;
                        }
                        if (handle_mouse_button_down(e, 510, 645, 540, 595, play_sound, clickButton)) {
                            Mix_PauseMusic();
                            isPaused = true;
                        }
                        if (handle_mouse_button_down(e, 695, 830, 540, 595, play_sound, clickButton)) {
                            Mix_ResumeMusic();
                            isPaused = false;
                        }
                    }
                }
                else if (!SetWindowSize1920x1080 && !SetWindowSize1280x720 && SetWindowSize800x600) {
                    if (!inSettingsPage && !inAuthorsPage) {
                        handle_mouse_button_down(e, 60, 370, 100, 190, play_sound, clickButton);
                        inSettingsPage = handle_mouse_button_down(e, 60, 370, 210, 300, play_sound, clickButton) ? true
                                                                                                                 : inSettingsPage;
                        inAuthorsPage = handle_mouse_button_down(e, 60, 370, 320, 410, play_sound, clickButton) ? true
                                                                                                                : inAuthorsPage;
                        quit = handle_mouse_button_down(e, 60, 370, 430, 520, play_sound, clickButton) ? true : quit;
                    }
                    if (inSettingsPage) {
                        if (handle_mouse_button_down(e, 190, 310, 315, 380, play_sound, clickButton)) {
                            SDL_SetWindowSize(window, 800, 600);
                            SetWindowSize1920x1080 = false;
                            SetWindowSize800x600 = true;
                            SetWindowSize1280x720 = false;
                        }
                        if (handle_mouse_button_down(e, 340, 460, 315, 380, play_sound, clickButton)) {
                            play_sound(clickButton);
                            SDL_SetWindowSize(window, 1280, 720);
                            SetWindowSize1920x1080 = false;
                            SetWindowSize800x600 = false;
                            SetWindowSize1280x720 = true;
                        }
                        if (handle_mouse_button_down(e, 490, 610, 315, 380, play_sound, clickButton)) {
                            play_sound(clickButton);
                            SDL_SetWindowSize(window, 1920, 1080);
                            SetWindowSize1920x1080 = true;
                            SetWindowSize800x600 = false;
                            SetWindowSize1280x720 = false;
                        }
                        if (handle_mouse_button_down(e, 300, 390, 455, 495, play_sound, clickButton)) {
                            Mix_PauseMusic();
                            isPaused = true;
                        }
                        if (handle_mouse_button_down(e, 450, 540, 455, 495, play_sound, clickButton)) {
                            Mix_ResumeMusic();
                            isPaused = false;
                        }
                    }
                }
            } else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE) {
                    if (inSettingsPage) {
                        play_sound(clickButton);
                        inSettingsPage = false;
                    }
                    if (e.key.keysym.sym == SDLK_ESCAPE) {
                        if (inAuthorsPage) {
                            play_sound(clickButton);
                            inAuthorsPage = false;
                        }
                    }
                }
            }
            if (SetWindowSize1920x1080) {
                win_buildFHD(renderer, window, backgroundTexture, buttonTextures, settingsButtonTextures,
                             authorsBackgroundTexture, clickButton, e, inSettingsPage, inAuthorsPage);
            } else if (SetWindowSize1280x720) {
                win_buildHD(renderer, window, backgroundTexture, buttonTextures, settingsButtonTextures,
                            authorsBackgroundTexture, clickButton, e, inSettingsPage, inAuthorsPage);
            } else if (SetWindowSize800x600) {
                win_buildNHD(renderer, window, backgroundTexture, buttonTextures, settingsButtonTextures,
                             authorsBackgroundTexture, clickButton, e, inSettingsPage, inAuthorsPage);
            }
        }
    }
    for (int i = 0; i < 4; ++i)
        SDL_DestroyTexture(*backgroundTexture);
    for (int i = 0; i < 7; ++i)
        SDL_DestroyTexture(settingsButtonTextures[i]);
    for (int i = 0; i < 4; ++i)
        SDL_DestroyTexture(buttonTextures[i]);
    SDL_DestroyTexture(authorsBackgroundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

int WinMain(int argc, char* args[]) {
    menu();
    return 0;
}