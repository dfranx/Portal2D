#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>

#include "LevelObstacle.h"

class Player
{
public:
    void Spawn(int x, int y);

    void Shoot(int x, int y, const std::vector<Obstacle>& obs);

    void Update();

    void Render(sf::RenderTarget& wnd);

    inline sf::Vector2f GetPosition() { return m_player.getPosition(); }

private:
    sf::CircleShape m_player; // visual representation of a player
};

#endif //__PLAYER_H__