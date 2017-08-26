#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>

#include "LevelObstacle.h"

class Ray;
class Level;

class Player
{
public:
    void Spawn(int x, int y);

    inline void SetLevel(Level* lvl) { m_lvl = lvl; }

    int Shoot(Ray& ray);

    void Update();

    void Render(sf::RenderTarget& wnd);

    inline sf::Vector2f GetPosition() { return m_player.getPosition(); }

private:
    sf::CircleShape m_player; // visual representation of a player
    Level* m_lvl;
};

#endif //__PLAYER_H__