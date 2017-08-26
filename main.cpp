#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Player.h"
#include "Level.h"
#include "Ray.h"

// TODO: change Player and LevelRenderer to sf::Drawable

int main()
{
    sf::RenderWindow wnd;
    wnd.create(sf::VideoMode(1280, 800), "Portal Prototype", sf::Style::Default);
    wnd.setFramerateLimit(60);

    // Level data
    Level level;
    level.Load("test.lvl");

    // Player
    Player player;
    
    // spawn player
    level.Reset(player);

    // Cast ray
    Ray ray;
    ray.Init();

    sf::Event ev;
    while (wnd.isOpen()) {
        while (wnd.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed)
                wnd.close();
            else if (ev.type == sf::Event::Resized)
                wnd.setView(sf::View(sf::FloatRect(0, 0, ev.size.width, ev.size.height)));
            else if (ev.type == sf::Event::MouseButtonPressed) {
                if (ray.GetEndId() == -1)
                    level.Reset(player);
                player.Shoot(ray);
            } else if (ev.type == sf::Event::MouseMoved)
                ray.Update(player, ev.mouseMove.x, ev.mouseMove.y, level.GetObstacles());
            else if (ev.type == sf::Event::KeyPressed) {
                if (ev.key.code == sf::Keyboard::R) // reset
                    level.Reset(player);
                else if (ev.key.code == sf::Keyboard::F1) // debug only!! allows ray rendering
                    ray.Visible = !ray.Visible;
            }
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