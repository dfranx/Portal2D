#include "Player.h"
#include "Level.h"
#include "Ray.h"

void Player::Spawn(int x, int y)
{
    m_player.setPosition(x*16+16, y*16+8);
    m_player.setRadius(8);
    m_player.setFillColor(sf::Color::Green);
    m_player.setOrigin(8, 8);
}

int Player::Shoot(Ray& ray)
{
    sf::Vector2f pos = ray.GetEndPosition();
    int id = ray.GetEndId();

    if (id == -1) {
        m_lvl->Reset(*this);
    } else if (id == 1) { // player completed level but just reset it
        m_lvl->Reset(*this);
    } else {
        m_player.setPosition(pos);
    }

    ray.Update(*this, pos.x, pos.y, m_lvl->GetObstacles());
    
    return id;
}

void Player::Update()
{

}

void Player::Render(sf::RenderTarget& wnd)
{
    wnd.draw(m_player);
}