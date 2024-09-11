#include "../../resource/header.h"

void init_texture_menuInGane(SDL_Renderer* renderer, SDL_Texture** backgroundsettings, SDL_Texture** menuInGameBackground, SDL_Texture* menuButtonTexture[], SDL_Texture* settingsButtonTextures[]) {

    *menuInGameBackground = load_texture("../menu/images/menuInGameBackground.PNG", renderer);
    *backgroundsettings = load_texture( "../menu/images/backgroundsettings.PNG", renderer);

    menuButtonTexture[0] = load_texture("../menu/images/menuButton1.png", renderer);
    menuButtonTexture[1] = load_texture("../menu/images/menuButton2.png", renderer);
    menuButtonTexture[2] = load_texture("../menu/images/menuButton3.png", renderer);

    settingsButtonTextures[0] = load_texture("../menu/images/settingsbutton_fullscreen1.PNG", renderer);
    settingsButtonTextures[1] = load_texture("../menu/images/settingsbutton_fullscreen2.PNG", renderer);
    settingsButtonTextures[2] = load_texture("../menu/images/settingsbutton_resolution1.PNG", renderer);
    settingsButtonTextures[3] = load_texture("../menu/images/settingsbutton_resolution2.PNG", renderer);
    settingsButtonTextures[4] = load_texture("../menu/images/settingsbutton_resolution3.PNG", renderer);
    settingsButtonTextures[5] = load_texture("../menu/images/buttonVolumeOFF.PNG", renderer);
    settingsButtonTextures[6] = load_texture("../menu/images/buttonVolumeON.PNG", renderer);
}