#include "../../resource/header.h"

Board board_build_thirdRoom(Board* room3){

    room3->wall1 = (SDL_Rect){1700, 395, 10,640};
    room3->wall2 = (SDL_Rect){220, 385, 1490,10};
    room3->wall3 = (SDL_Rect){220, 1030, 1490,10};
    room3->wall4 = (SDL_Rect){210, 385, 10,655};
    room3->wall5 = (SDL_Rect){1540, 520, 10, 370};
    room3->wall6 = (SDL_Rect){1290, 520, 10,510};
    room3->wall7 = (SDL_Rect){1290, 515, 260,10};
    room3->wall8 = (SDL_Rect){210,890 , 1340,10};
    room3->wall9 = (SDL_Rect){260, 385, 10,655};
    room3->wall10 = (SDL_Rect){550, 690, 500,10};
    room3->wall11 = (SDL_Rect){550, 510, 500,10};
    room3->wall12 = (SDL_Rect){550, 520, 10,180};
    room3->wall13 = (SDL_Rect){1050, 390, 10,310};
    room3->wall14 = (SDL_Rect){685, 385, 10,130};
}