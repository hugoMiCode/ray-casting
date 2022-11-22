#pragma once
#include <SFML/Graphics.hpp>

class Boundray
{
public:
	Boundray(double, double, double, double);
	void show(sf::RenderWindow&);
	sf::Vector2f getPositionA();
	sf::Vector2f getPositionB();

private:
	sf::ConvexShape wall;
	sf::Vector2f a;
	sf::Vector2f b;
};

