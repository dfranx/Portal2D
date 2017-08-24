#include "Player.h"

void Player::Spawn(int x, int y)
{
    m_player.setPosition(x*16+16, y*16+8);
    m_player.setRadius(8);
    m_player.setFillColor(sf::Color::Green);
    m_player.setOrigin(8, 8);
}

void Player::Shoot(int x, int y, const std::vector<Obstacle>& obs)
{
    
}

void Player::Update()
{

}

void Player::Render(sf::RenderTarget& wnd)
{
    wnd.draw(m_player);
}