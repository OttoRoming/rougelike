#ifndef MAP_H
#define MAP_H

#include <raylib.h>

typedef enum {
    GRASS,
    DIRT,
} Ground_e;

typedef enum {
    NO
} Structure_e;

typedef struct {
    Ground_e ground;
    Structure_e structure;
} Tile;

typedef struct {
    Tile **tiles;
} Floor_t;

typedef struct {
    Floor_t floor;
} Map_t;

#endif
