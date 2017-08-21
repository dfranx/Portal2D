#ifndef __LEVEL_BUILDER_H__
#define __LEVEL_BUILDER_H__

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

    // Add obstacle to map
    inline void AddObstacle(Obstacle ob) { m_obs.push_back(ob); }

    // Get obstacles for level
    inline std::vector<Obstacle>& GetObstacles() { return m_obs; }

private:
    std::vector<Obstacle> m_obs;
};

#endif //__LEVEL_BUILDER_H__