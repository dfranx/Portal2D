#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "LevelBuilder.h"
#include "LevelRenderer.h"
#include "Player.h"
#include "Ray.h"

// TODO: change Player and LevelRenderer to sf::Drawable

int main()
{
    sf::RenderWindow wnd;
    wnd.create(sf::VideoMode(1280, 800), "Portal Prototype", sf::Style::Default);
    wnd.setFramerateLimit(60);

    // Load/Create test level
    LevelBuilder builder;
    builder.AddObstacle({ 0, 2, 2, 1, 5 });
    builder.AddObstacle({ 0, 2, 2, 5, 1 });
    builder.AddObstacle({ 0, 5, 5, 1, 5 });
    builder.AddObstacle({ 0, 2, 12, 1, 5 });
    builder.AddObstacle({ 0, 5, 17, 1, 5 });
    
    // Actual level renderer
    LevelRenderer level;
    level.Create(builder);

    // Player
    Player player;
    player.Spawn(4, 5);

    // Cast ray
    Ray ray;

    sf::Event ev;
    while (wnd.isOpen()) {
        while (wnd.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed)
                wnd.close();
            else if (ev.type == sf::Event::Resized)
                wnd.setView(sf::View(sf::FloatRect(0, 0, ev.size.width, ev.size.height)));
            else if (ev.type == sf::Event::MouseButtonPressed)
                player.Shoot(ev.mouseButton.x, ev.mouseButton.y, builder.GetObstacles());
            else if (ev.type == sf::Event::MouseMoved)
                ray.Update(player, ev.mouseMove.x, ev.mouseMove.y, builder.GetObstacles());
        }

        player.Update();

        wnd.clear();

        level.Render(wnd);
        player.Render(wnd);
        ray.Render(wnd);

        wnd.display();
    }

    return 0;
}