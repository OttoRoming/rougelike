#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <raylib.h>

#define MAX_HEALTH 5

typedef struct {
    Camera2D camera;
    Player_t player;
} Game_t;

void game_update(Game_t *game);

#endif
