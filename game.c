#include "game.h"
#include "config.h"
#include "player.h"
#include <raylib.h>


void draw_background_gradient() {
    Rectangle window_rectangle = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    DrawRectangleGradientEx(window_rectangle, LIGHTGRAY, LIGHTGRAY, LIGHTGRAY, DARKGRAY);
}


void game_update(Game_t *game) {
    BeginDrawing();

    // Draw background
    draw_background_gradient();

    BeginMode2D(game->camera);

    // Draw game world
    player_update(&game->player);

    EndMode2D();

    // Draw HUD

    EndDrawing();
}
