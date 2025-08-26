#include "player.h"
#include <raylib.h>

void player_update(Player_t *player) {
  Vector2 size = {1, 1};
  DrawRectangleV(player->position, size, RED);
}
