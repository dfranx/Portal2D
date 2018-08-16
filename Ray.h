#ifndef __PORTAL2D_RAY_H__
#define __PORTAL2D_RAY_H__

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <vector>

#include "LevelObstacle.h"

class Player;

class Ray
{
public:
	// initialize some values
	Ray();

	// update ray's segments
	//	pl -> player which casts a ray
	//	mx -> mouse position x
	//	my -> mouse position y
	//	obs-> all obstacles in a level (or only near ones - for example we can send only obstacles whose distance from the player is <= 600)
    void Update(Player pl, sf::Vector2i mouse, const std::vector<Obstacle>& obs);

	// render the line segments
    void Render(sf::RenderTarget& tgt);

	// should this ray be rendered?
    bool Visible;

	// get information about ray's end
    inline sf::Vector2f GetEndPosition() { return m_pos; }
    inline int GetEndId() { return m_id; }

private:
    // check for collision using all ray segments with all the given obstacles
    int check(const sf::Vector2f& start, const sf::Vector2f& end, const std::vector<Obstacle>& obs, sf::Vector2f& normal, sf::Vector2f& pos);

	// check for a single line with line collision
	bool line(float& ext, sf::Vector2f& normal, const sf::Vector2f& rStart, const sf::Vector2f& rEnd, const sf::Vector2f& cStart, const sf::Vector2f& cEnd);

    std::vector<sf::Vertex> m_ln;	// visual representation of a ray

    // collision data
    int m_id;				// contains obstacle id that the ray is colliding with at the end
    sf::Vector2f m_pos;		// end position of a ray
};

#endif //__PORTAL2D_RAY_H__