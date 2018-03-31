#include "LevelBuilder.h"

#include <fstream>

bool LevelBuilder::Load(const std::string& filename) {
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    
	if (!file.is_open())
		return false;

	// first 2 bytes tell us spawn position
    m_spawn.x = file.get();
    m_spawn.y = file.get();
    
    m_obs.clear();

    Obstacle ob;
    while (file.read((char*)&ob, sizeof(Obstacle))) // read all obstacles from file while we can
        m_obs.push_back(ob);
    
    file.close();  

	return true;
}

void LevelBuilder::Save(const std::string& filename) {
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    
	// save spawn position
    file.put(m_spawn.x);
    file.put(m_spawn.y);
    
	// serialize all obstacles
    for (auto& ob : m_obs)
        file.write((char*)&ob, sizeof(Obstacle));

    file.close();  
}