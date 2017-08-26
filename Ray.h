#ifndef __RAY_H__
#define __RAY_H__

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <vector>

#include "LevelObstacle.h"

class Player;

class Ray
{
public:
    void Init();

    void Update(Player pl, int mx, int my, const std::vector<Obstacle>& obs);

    void Render(sf::RenderTarget& tgt);

    bool Visible;

    inline sf::Vector2f GetEndPosition() { return m_pos; }
    inline int GetEndId() { return m_id; }

private:
    // Bresenham's line algorithm
    int line(int x0, int y0, int x1, int y1, const std::vector<Obstacle>& obs, sf::Vector2f& pos, bool& vertical);

    // is it bouncing off of left and right side or top and down side of obstacle?
    bool vertical(int x, int y, Obstacle ob);

    std::vector<sf::Vertex> m_ln; // visual representation of ray

    // collision data
    int m_id;
    sf::Vector2f m_pos;
};

#endif //__RAY_H__