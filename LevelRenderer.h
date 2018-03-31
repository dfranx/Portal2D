#ifndef __PORTAL2D_LEVEL_RENDERER_H__
#define __PORTAL2D_LEVEL_RENDERER_H__

#include "LevelBuilder.h"
#include <SFML/Graphics/RenderTarget.hpp>

class LevelRenderer
{
public:
	///////////////////////////////////////
	// get obstacles from LevelBuilder
	///////////////////////////////////////
    void Create(LevelBuilder& builder);

	///////////////////////////////////////
	// render obstacles
	///////////////////////////////////////
    void Render(sf::RenderTarget& tgt);

private:
    std::vector<Obstacle> m_obs; // list of all obstacles
};

#endif //__PORTAL2D_LEVEL_RENDERER_H__