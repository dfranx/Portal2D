#ifndef __PORTAL2D_LEVEL_BUILDER_H__
#define __PORTAL2D_LEVEL_BUILDER_H__

#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>

#include "LevelObstacle.h"

class LevelBuilder
{
public:
	///////////////////////////////////////
    // Load level from file, returns true
	// if we successfully loaded file
	// information
	///////////////////////////////////////
    bool Load(const std::string& file);

	///////////////////////////////////////
    // Save level to file
	///////////////////////////////////////
    void Save(const std::string& file);

	///////////////////////////////////////
    // Set player spawn position
	///////////////////////////////////////
    inline void SetSpawn(int x, int y) { m_spawn = sf::Vector2i(x,y); }

	///////////////////////////////////////
    // Get player spawn position
	///////////////////////////////////////
    inline sf::Vector2i GetSpawn() { return m_spawn; }

	///////////////////////////////////////
    // Add obstacle to map
	///////////////////////////////////////
    inline void AddObstacle(Obstacle ob) { m_obs.push_back(ob); }

	///////////////////////////////////////
    // Get level's obstacles
	///////////////////////////////////////
    inline std::vector<Obstacle>& GetObstacles() { return m_obs; }

private:
    std::vector<Obstacle> m_obs;	// list of all obstacles
    sf::Vector2i m_spawn;			// list 
};

#endif //__PORTAL2D_LEVEL_BUILDER_H__