#ifndef __PORTAL2D_PLAYER_H__
#define __PORTAL2D_PLAYER_H__

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>

#include "LevelObstacle.h"

class Ray;
class Level;

class Player
{
public:
	///////////////////////////////////////
	// sets the player position
	///////////////////////////////////////
    void Spawn(int x, int y);

	///////////////////////////////////////
	// set current level
	///////////////////////////////////////
    inline void SetLevel(Level* lvl) { m_lvl = lvl; }

	///////////////////////////////////////
	// update player information according
	// to the given ray information and then
	// update ray information based on a new
	// player position
	///////////////////////////////////////
    int Shoot(Ray& ray);

	///////////////////////////////////////
	// render the player
	///////////////////////////////////////
    void Render(sf::RenderTarget& wnd);

	// get player position
    inline sf::Vector2f GetPosition() { return m_player.getPosition(); }

private:
    sf::CircleShape m_player;	// visual representation of a player
    Level* m_lvl;				// pointer to current level - gives the player information about current level
};

#endif //__PORTAL2D_PLAYER_H__