#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "LevelBuilder.h"
#include "LevelRenderer.h"

int main() {
    sf::RenderWindow wnd;
    wnd.create(sf::VideoMode(1280, 800), "Portal Prototype", sf::Style::Default);

    // Load/Create test level
    LevelBuilder builder;
    builder.AddObstacle({ 0, 2, 2, 10, 1 });
    builder.AddObstacle({ 0, 2, 2, 1, 10 });
    
    // Actual level renderer
    LevelRenderer level;
    level.Create(builder);

    sf::Event ev;
    while (wnd.isOpen()) {
        while (wnd.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed)
                wnd.close();
        }

        wnd.clear();

        level.Render(wnd);

        wnd.display();
    }

    return 0;
}