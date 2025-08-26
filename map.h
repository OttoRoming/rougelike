#ifndef MAP_H
#define MAP_H

#include <raylib.h>
#include <stddef.h>

typedef enum {
  GRASS,
  DIRT,
} Ground_e;

typedef enum { NO } Structure_e;

typedef struct {
  Ground_e ground;
  Structure_e structure;
} Tile_t;

typedef struct {
  size_t width;
  size_t height;
  Tile_t **tiles;
} Floor_t;

typedef struct {
  Floor_t floor;
} Map_t;

Map_t new_map();
void map_update(Map_t *map);

#endif
