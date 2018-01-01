#ifndef WALL_H
#define WALL_H

#include "Tile.h"

class Wall : public Tile {
public:
    Wall() : Tile('#') {};
};

#endif
