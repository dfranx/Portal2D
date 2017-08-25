#include "LevelBuilder.h"

#include <fstream>

void LevelBuilder::Load(const std::string& filename) {
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    
    m_spawn.x = file.get();
    m_spawn.y = file.get();
    
    m_obs.clear();

    Obstacle ob;
    while (file.read((char*)&ob, sizeof(Obstacle)))
        m_obs.push_back(ob);
    
    file.close();  
}

void LevelBuilder::Save(const std::string& filename) {
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    
    file.put(m_spawn.x);
    file.put(m_spawn.y);
    
    for (auto& ob : m_obs)
        file.write((char*)&ob, sizeof(Obstacle));

    file.close();  
}