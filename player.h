#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include <stdint.h>

typedef struct {
  Vector2 velocity;
  Vector2 position;
  uint8_t health;
} Player_t;

void player_update(Player_t *player, Camera2D *camera);

#endif // PLAYER_H
