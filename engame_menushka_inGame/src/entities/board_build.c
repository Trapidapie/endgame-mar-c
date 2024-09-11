#include "../../resource/header.h"

Board board_build(int roomWidth, int roomHeight, SDL_Texture* bgPath) {
    int roomX = (SCREEN_WIDTH - roomWidth) / 2;
    int roomY = (int)((SCREEN_HEIGHT - roomHeight) / 1.17);

    Board room;
    room.topWall = (SDL_Rect){roomX, roomY - 140, roomWidth, 10};
    room.bottomWall = (SDL_Rect){roomX, roomY + roomHeight, roomWidth, 10};
    room.leftWall = (SDL_Rect){roomX, roomY - 140, 10, roomHeight + 140};
    room.rightWall = (SDL_Rect){roomX + roomWidth, roomY -140 , 10, roomHeight + 140};
    room.bg = bgPath;

    printf("Top Wall: %d %d %d %d\n", room.topWall.x, room.topWall.y, room.topWall.w, room.topWall.h);
    printf("Bottom Wall: %d %d %d %d\n", room.bottomWall.x, room.bottomWall.y, room.bottomWall.w, room.bottomWall.h);
    printf("Left Wall: %d %d %d %d\n", room.leftWall.x, room.leftWall.y, room.leftWall.w, room.leftWall.h);
    printf("Right Wall: %d %d %d %d\n", room.rightWall.x, room.rightWall.y, room.rightWall.w, room.rightWall.h);

    return room;
}