#ifndef __PORTAL2D_LEVEL_OBSTACLE_H__
#define __PORTAL2D_LEVEL_OBSTACLE_H__

#include <SFML/Graphics/Rect.hpp>
#include "Config.h"

struct Obstacle
{
    char Id;		// id - what type of obstacle is this?
    char X, Y;		// position and size
    char W, H;

    inline sf::IntRect GetBounds() { return { X*UNIT_WIDTH, Y*UNIT_HEIGHT, W*UNIT_WIDTH, H*UNIT_HEIGHT }; }
};

#endif //__PORTAL2D_LEVEL_OBSTACLE_H__