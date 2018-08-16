#ifndef __PORTAL2D_LEVEL_BUILDER_H__
#define __PORTAL2D_LEVEL_BUILDER_H__

#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>

#include "LevelObstacle.h"

class LevelBuilder
{
public:
    // load level from file
    bool Load(const std::string& file);

    // save level to file
    void Save(const std::string& file);

    // set player spawn position
    inline void SetSpawn(int x, int y) { m_spawn = sf::Vector2i(x,y); }

    // get player spawn position
    inline sf::Vector2i GetSpawn() { return m_spawn; }

    // add a obstacle to map
    inline void AddObstacle(Obstacle ob) { m_obs.push_back(ob); }

    // get all the obstacles in this level
    inline std::vector<Obstacle>& GetObstacles() { return m_obs; }

private:
    std::vector<Obstacle> m_obs;	// list of all obstacles
    sf::Vector2i m_spawn;			// where should our player spawn?
};

#endif //__PORTAL2D_LEVEL_BUILDER_H__