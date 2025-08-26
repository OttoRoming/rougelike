#include "map.h"
#include <raylib.h>
#include <stdlib.h>

void tile_update(Tile_t *tile, size_t x, size_t y) {
  DrawRectangle(x, y, 1, 1, BROWN);
}

void floor_update(Floor_t *floor) {
  for (size_t x = 0; x < floor->width; x++) {
    for (size_t y = 0; y < floor->width; y++) {
      tile_update(&floor->tiles[x][y], x, y);
    }
  }
}

Map_t new_map() {
  size_t width = 128;
  size_t height = 128;

  Tile_t **tiles = malloc(sizeof(Tile_t *) * width);
  for (size_t x = 0; x < width; x++) {
    tiles[x] = malloc(sizeof(Tile_t) * height);
  };

  return (Map_t){.floor = {
                     .width = width,
                     .height = height,
                     .tiles = tiles,
                 }};
}

void map_update(Map_t *map) { floor_update(&map->floor); }
