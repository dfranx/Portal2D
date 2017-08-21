#ifndef __LEVEL_RENDERER_H__
#define __LEVEL_RENDERER_H__

#include "LevelBuilder.h"
#include <SFML/Graphics/RenderTarget.hpp>

class LevelRenderer
{
public:
    void Create(LevelBuilder& builder);

    void Render(sf::RenderTarget& tgt);

private:
    std::vector<Obstacle> m_obs;
};

#endif //__LEVEL_RENDERER_H__