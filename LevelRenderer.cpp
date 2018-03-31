#include "LevelRenderer.h"
#include "Config.h"

#include <SFML/Graphics/RectangleShape.hpp>

void LevelRenderer::Create(LevelBuilder& builder)
{
    m_obs = builder.GetObstacles();
}

void LevelRenderer::Render(sf::RenderTarget& tgt)
{
    for (auto& ob : m_obs) {
        sf::RectangleShape shape;
        shape.setPosition(ob.X*UNIT_WIDTH, ob.Y*UNIT_HEIGHT); // change this constants!
        shape.setSize(sf::Vector2f(ob.W*UNIT_WIDTH, ob.H*UNIT_HEIGHT));
		shape.setFillColor(sf::Color::White);

        if (ob.Id == 1)
            shape.setFillColor(sf::Color::Green);

        tgt.draw(shape);
    }
}