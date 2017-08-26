#ifndef __LEVEL_H__
#define __LEVEL_H__
#include "LevelBuilder.h"
#include "LevelRenderer.h"

class Player;

class Level
{
public:
    void Load(std::string file);

    void Reset(Player& pl);

    void Render(sf::RenderTarget& tgt);

    inline const std::vector<Obstacle> GetObstacles() { return m_builder.GetObstacles(); }

private:
    LevelBuilder m_builder;
    LevelRenderer m_renderer;
};

#endif //__LEVEL_H__