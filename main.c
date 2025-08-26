#include "config.h"
#include "game.h"
#include "player.h"
#include <raylib.h>

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Ottos Rouglike");

  Camera2D camera = {
      .offset = {(float)WINDOW_WIDTH / 2, (float)WINDOW_HEIGHT / 2},
      .target = {0, 0},
      .rotation = 0,
      .zoom = 32,
  };

  Player_t player = {
      .position = {0, 0},
      .health = 5,
  };

  Game_t game = {
      .camera = camera,
      .player = player,
  };

  while (!WindowShouldClose()) {
    game_update(&game);
  }
}
