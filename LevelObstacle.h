#ifndef __LEVEL_OBSTACLE_H__
#define __LEVEL_OBSTACLE_H__

#include <SFML/Graphics/Rect.hpp>

struct Obstacle
{
    char Id;
    char X, Y;
    char W, H;

    inline sf::IntRect GetBounds() { return { X*16, Y*16, W*16, H*16 }; }
};

#endif //__LEVEL_OBSTACLE_H__