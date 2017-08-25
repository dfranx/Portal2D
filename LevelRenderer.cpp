#include "LevelRenderer.h"

#include <SFML/Graphics/RectangleShape.hpp>

void LevelRenderer::Create(LevelBuilder& builder)
{
    m_obs = builder.GetObstacles();
}

void LevelRenderer::Render(sf::RenderTarget& tgt)
{
    for (auto& ob : m_obs) {
        sf::RectangleShape shape;
        shape.setPosition(ob.X*16, ob.Y*16); // change this constants!
        shape.setSize(sf::Vector2f(ob.W*16, ob.H*16));

        if (ob.Id == 1)
            shape.setFillColor(sf::Color::Green);

        tgt.draw(shape);
    }
}