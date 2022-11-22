#pragma once
#include <SFML/Graphics.hpp>
#include "Ray.h"
#include "Boundray.h"
#include <vector>

class Particle
{
public:
	Particle(sf::RenderWindow&, int angle);
	void show(sf::RenderWindow&);
	void look(std::vector<Boundray>&, sf::RenderWindow&);
	void look1(Boundray&, sf::RenderWindow&);
	void setPosition(double, double);
	double dist(sf::Vector2f&);

private:
	sf::Vector2f pos;
	std::vector<Ray> rays;
};

