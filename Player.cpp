#include "Player.h"
#include "Level.h"
#include "Ray.h"

void Player::Spawn(int x, int y)
{
    m_player.setPosition((x + 1.f)*UNIT_WIDTH, (y + 0.5f)*UNIT_HEIGHT);
    m_player.setRadius((UNIT_WIDTH+UNIT_HEIGHT)/4); // get average radius
    m_player.setFillColor(sf::Color::Green);
    m_player.setOrigin(UNIT_WIDTH/2, UNIT_HEIGHT/2);
}

int Player::Shoot(Ray& ray)
{
    sf::Vector2f pos = ray.GetEndPosition();
    int id = ray.GetEndId();

    if (id == -1)		// we didnt hit anything -> player died -> reset the level
        m_lvl->Reset(*this);
	else if (id == 1) {	// player completed level but just reset it
		m_lvl->Reset(*this);
		printf("Congratulations! You just completed the level!");
	} else				// player moved
        m_player.setPosition(pos);

	/*
		NOTE: you can add more platforms
		else if (id == 2) playerDied();
		else if (id == 3) teleportPlayer(x,y);
		etc..
	*/

	// we have new position = we need to update the ray
    ray.Update(*this, sf::Vector2i(pos), m_lvl->GetObstacles());
    
    return id;
}

void Player::Render(sf::RenderTarget& wnd)
{
    wnd.draw(m_player);
}