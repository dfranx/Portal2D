#include "Level.h"
#include "Player.h"

bool Level::Load(std::string file)
{
    bool ret = m_builder.Load(file);
    m_renderer.Create(m_builder);

	return ret;
}

void Level::Reset(Player& pl)
{
    pl.Spawn(m_builder.GetSpawn().x, m_builder.GetSpawn().y);
    pl.SetLevel(this);
}

void Level::Render(sf::RenderTarget& tgt)
{
    m_renderer.Render(tgt);
}