#ifndef __RAY_H__
#define __RAY_H__

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <vector>

#include "Player.h"
#include "LevelObstacle.h"

class Ray
{
public:
    void Update(Player pl, int mx, int my, const std::vector<Obstacle>& obs);

    void Render(sf::RenderTarget& tgt);

private:
    // Bresenham's line algorithm
    bool line(int x0, int y0, int x1, int y1, const std::vector<Obstacle>& obs, sf::Vector2f& pos, bool& vertical);

    // is it bouncing off of left and right side or top and down side of obstacle?
    bool vertical(int x, int y, Obstacle ob);

    std::vector<sf::Vertex> m_ln; // visual representation of ray
};

#endif //__RAY_H__