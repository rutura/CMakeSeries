#include "core.h"
#include <SFML/Graphics.hpp>

/**
    @brief The entry point of the application. Uses the app function.
*/

int main(int argc, char **argv) {
  //app(argc, argv);
  sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Black);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Yellow);
        window.draw(shape);
        window.display();
    }

    return 0;
  return 0;
}