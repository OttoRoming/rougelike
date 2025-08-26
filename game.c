#include "game.h"
#include "config.h"
#include "map.h"
#include "player.h"
#include <raylib.h>

void draw_background_gradient() {
  Rectangle window_rectangle = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

  DrawRectangleGradientEx(window_rectangle, LIGHTGRAY, LIGHTGRAY, LIGHTGRAY,
                          DARKGRAY);
}

void game_update(Game_t *game) {
  BeginDrawing();

  // Draw background
  draw_background_gradient();

  BeginMode2D(game->camera);

  // Draw game world
  map_update(&game->map);
  player_update(&game->player, &game->camera);

  EndMode2D();

  // Draw HUD
  DrawFPS(0, 0);

  EndDrawing();
}
