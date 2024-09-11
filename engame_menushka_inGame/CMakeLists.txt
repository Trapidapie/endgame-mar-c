cmake_minimum_required(VERSION 3.27)
project(endgame C)

set(CMAKE_C_STANDARD 11)

include_directories(resource)
include_directories(src)

link_directories(resource/SDL2-2.30.0/lib/x64)
link_directories(resource/SDL2_image-2.8.2/lib/x64)
link_directories(resource/SDL2_mixer-2.8.0/lib/x64)
link_directories(resource/SDL2_ttf-2.22.0/lib/x64)

add_executable(endgame
        resource/header.h
        src/entities/board_build.c
        src/entities/init_first_room.c
        src/errs/sdl_init.c
        src/errs/sdl_window.c
        src/errs/sdl_render.c
        src/graphics/load_texture.c
        src/graphics/load_sound.c
        src/graphics/play_sound.c
        src/render/render_button.c
        src/mechanics/update_hero.c
        src/mechanics/check_collision.c
        src/menu/init_texture_menu.c
        src/menu/win_buildFHD.c
        src/menu/win_buildHD.c
        src/menu/win_buildNHD.c
        src/menu/handle_mouse_button_down.c
        src/menu/menu_main.c
        src/menu/play_click_sound.c
        src/render/render_all_room.c
        src/render/render_hero.c
        src/render/render_bg.c
        src/render/render_button.c
        src/render/render_obj.c
        src/render/render_room.c
        src/render/render_main.c
        src/start_game.c
        src/menu/win_buildMenuButtons.c
        src/menu/win_build_Settings.c
        src/menu/init_texture_menuInGame.c
        src/render/render_board_thirdRoom.c
        src/mechanics/update_hero_thirdRoom.c
        src/entities/board_build_thirdRoom.c
)

target_link_libraries(endgame SDL2 SDL2_ttf SDL2_mixer SDL2_image)
