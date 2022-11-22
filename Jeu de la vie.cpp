#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ray.h"
#include "Boundray.h"
#include "Particle.h"

void draw(sf::RenderWindow&, Particle&, std::vector<Boundray>);
void update(std::vector<Boundray>&, sf::RenderWindow&);

int main()
{
    int _angle;
    std::cout << "Rentre un entier [1 ; 360] : "; 
    std::cin >> _angle;
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "Raycasting");
    std::vector<Boundray> walls{};

    update(walls, window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            update(walls, window);
        }

        window.clear(sf::Color::Black);
        Particle particle(window, _angle);
        draw(window, particle, walls);
        window.display();
    }

    return 0;
}

void draw(sf::RenderWindow& window, Particle& particle, std::vector<Boundray> walls)
{
    for (unsigned short int i{ 0 }; i < walls.size(); i++)
    {
        walls[i].show(window);
    }

    particle.look(walls, window);
    particle.show(window);
    particle.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
}
void update(std::vector<Boundray>& walls, sf::RenderWindow& window)
{
    while (walls.size() != 0)
    {
        walls.pop_back();
    }

    double x1, y1, x2, y2;
    for (unsigned int i{ 0 }; i < 5; i++)
    {
        x1 = rand() % (0, window.getSize().x);
        y1 = rand() % (0, window.getSize().y);
        x2 = rand() % (0, window.getSize().x);
        y2 = rand() % (0, window.getSize().y);

        walls.push_back(Boundray(x1, y1, x2, y2));
    }

    walls.push_back(Boundray(0, 0, window.getSize().x, 0));
    walls.push_back(Boundray(0, 0, 0, window.getSize().y));
    walls.push_back(Boundray(window.getSize().x, 0, window.getSize().x, window.getSize().y));
    walls.push_back(Boundray(0, window.getSize().y, window.getSize().x, window.getSize().y));
}