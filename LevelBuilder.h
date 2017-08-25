#ifndef __LEVEL_BUILDER_H__
#define __LEVEL_BUILDER_H__

#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>

#include "LevelObstacle.h"

class LevelBuilder
{
public:
    // Get all data from file
    void Load(const std::string& file);

    // Save to file
    void Save(const std::string& file);

    // Set player spawn position
    inline void SetSpawn(int x, int y) { m_spawn = sf::Vector2i(x,y); }

    // Get player spawn position
    inline sf::Vector2i GetSpawn() { return m_spawn; }

    // Add obstacle to map
    inline void AddObstacle(Obstacle ob) { m_obs.push_back(ob); }

    // Get obstacles for level
    inline std::vector<Obstacle>& GetObstacles() { return m_obs; }

private:
    std::vector<Obstacle> m_obs;
    sf::Vector2i m_spawn;
};

#endif //__LEVEL_BUILDER_H__