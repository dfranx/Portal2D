#ifndef __PORTAL2D_LEVEL_H__
#define __PORTAL2D_LEVEL_H__
#include "LevelBuilder.h"
#include "LevelRenderer.h"

class Player;

class Level
{
public:
	///////////////////////////////////////
	// load level from file
	///////////////////////////////////////
    bool Load(std::string file);

	///////////////////////////////////////
	// reset players position
	///////////////////////////////////////
    void Reset(Player& pl);

	///////////////////////////////////////
	// render level
	///////////////////////////////////////
    void Render(sf::RenderTarget& tgt);

	// get all obstacles
    inline const std::vector<Obstacle> GetObstacles() { return m_builder.GetObstacles(); }

private:
    LevelBuilder m_builder;		// object used for getting and building level information
    LevelRenderer m_renderer;	// object used for rendering that level information
};

#endif //__PORTAL2D_LEVEL_H__