#include "../../resource/header.h"

void init_texture_menu(SDL_Renderer* renderer, SDL_Texture* backgroundTexture[], SDL_Texture** authorsBackgroundTexture, SDL_Texture* buttonTextures[], SDL_Texture* settingsButtonTextures[]) {
    backgroundTexture[0] = load_texture("../menu/images/background.PNG", renderer);
    backgroundTexture[1] = load_texture("../menu/images/background2.PNG", renderer);
    backgroundTexture[2] = load_texture("../menu/images/background3.PNG", renderer);
    backgroundTexture[3] = load_texture( "../menu/images/backgroundsettings.PNG", renderer);

    *authorsBackgroundTexture = load_texture("../menu/images/backgroundauthors.PNG", renderer);

    buttonTextures[0] = load_texture("../menu/images/button1.PNG", renderer);
    buttonTextures[1] = load_texture( "../menu/images/button2.PNG", renderer);
    buttonTextures[2] = load_texture("../menu/images/button3.PNG", renderer);
    buttonTextures[3] = load_texture("../menu/images/button4.PNG", renderer);

    settingsButtonTextures[0] = load_texture("../menu/images/settingsbutton_fullscreen1.PNG", renderer);
    settingsButtonTextures[1] = load_texture("../menu/images/settingsbutton_fullscreen2.PNG", renderer);
    settingsButtonTextures[2] = load_texture("../menu/images/settingsbutton_resolution1.PNG", renderer);
    settingsButtonTextures[3] = load_texture("../menu/images/settingsbutton_resolution2.PNG", renderer);
    settingsButtonTextures[4] = load_texture("../menu/images/settingsbutton_resolution3.PNG", renderer);
    settingsButtonTextures[5] = load_texture("../menu/images/buttonVolumeOFF.PNG", renderer);
    settingsButtonTextures[6] = load_texture("../menu/images/buttonVolumeON.PNG", renderer);
}