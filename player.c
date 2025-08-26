#include "player.h"
// #include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

#define PLAYER_SPEED 20
#define ATTACK_RECOIL 5

void attack(Player_t *player, float angle) {
  Vector2 recoil_vector = {ATTACK_RECOIL, 0};
  recoil_vector = Vector2Rotate(recoil_vector, angle);
  recoil_vector.y = -recoil_vector.y;

  player->velocity = Vector2Subtract(player->velocity, recoil_vector);
  printf("velocity: x: %f, y: %f\n", player->velocity.x, player->velocity.y);

  // Vector2 v = Vector2Rotate((Vector2){10, 0}, angle);
  // Vector2 v ={
  //     .x = cosf(angle*)
  // };
  // printf("x: %f, y: %f\n", v.x, v.y);
  // DrawLineV(Vector2 startPos, Vector2 endPos, Color color)
}

void handle_controls(Player_t *player, Camera2D *camera) {
  // NOTE: this is basically free
  float dt = GetFrameTime();

  if (IsKeyDown(KEY_W)) {
    player->velocity.y -= dt * PLAYER_SPEED;
  }
  if (IsKeyDown(KEY_A)) {
    player->velocity.x -= dt * PLAYER_SPEED;
  }
  if (IsKeyDown(KEY_S)) {
    player->velocity.y += dt * PLAYER_SPEED;
  }
  if (IsKeyDown(KEY_D)) {
    player->velocity.x += dt * PLAYER_SPEED;
  }

  // if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    Vector2 mouse_position = GetScreenToWorld2D(GetMousePosition(), *camera);
    float angle = Vector2LineAngle(player->position, mouse_position);
    attack(player, angle);
  }
}

void handle_physics(Player_t *player) {
  float dt = GetFrameTime();

  Vector2 distance = Vector2Scale(player->velocity, dt);
  player->position = Vector2Add(player->position, distance);
  player->velocity = Vector2Scale(player->velocity, 1 - 1 * dt);
}

void player_update(Player_t *player, Camera2D *camera) {
  handle_physics(player);
  handle_controls(player, camera);

  Vector2 size = {1, 1};
  DrawRectangleV(player->position, size, RED);
}
