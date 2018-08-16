#ifndef __PORTAL2D_LEVEL_RENDERER_H__
#define __PORTAL2D_LEVEL_RENDERER_H__

#include "LevelBuilder.h"
#include <SFML/Graphics/RenderTarget.hpp>

class LevelRenderer
{
public:
	// get the list of obstacles from LevelBuilder
    void Create(LevelBuilder& builder);

	// render all the obstacles
    void Render(sf::RenderTarget& tgt);

private:
    std::vector<Obstacle> m_obs;
};

#endif //__PORTAL2D_LEVEL_RENDERER_H__