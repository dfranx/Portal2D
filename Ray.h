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
	///////////////////////////////////////
	// initialize some values
	///////////////////////////////////////
	Ray();

	///////////////////////////////////////
	// update ray's segments
	//	pl -> player which casts a ray
	//	mx -> mouse position x
	//	my -> mouse position y
	//	obs-> all obstacles in a level (or only near ones - for example we can send only obstacles whose distance from the player is <= 600)
	///////////////////////////////////////
    void Update(Player pl, int mx, int my, const std::vector<Obstacle>& obs);

	///////////////////////////////////////
	// render this ray to a window
	///////////////////////////////////////
    void Render(sf::RenderTarget& tgt);

	///////////////////////////////////////
	// should this ray be rendered?
	///////////////////////////////////////
    bool Visible;

	// get information about ray's end
    inline sf::Vector2f GetEndPosition() { return m_pos; }
    inline int GetEndId() { return m_id; }

private:
    // Bresenham's line algorithm (if it didnt hit any obstacle { return value less than 0 } else { return obstacle id }) 
    int line(int x0, int y0, int x1, int y1, const std::vector<Obstacle>& obs, sf::Vector2f& pos, bool& vertical);

    // is it bouncing off of left and right side or top and down side?
    bool vertical(int x, int y, Obstacle ob);

    std::vector<sf::Vertex> m_ln;	// visual representation of a ray

    // collision data
    int m_id;				// contains obstacle id
    sf::Vector2f m_pos;		// end position of a ray
};

#endif //__PORTAL2D_RAY_H__