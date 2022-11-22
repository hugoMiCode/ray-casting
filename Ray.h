#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "Boundray.h"
#include <cmath>
#include <iostream>


class Ray
{
public:
	Ray(sf::Vector2f, double);
	void show(sf::RenderWindow&);
	sf::Vector2f cast(Boundray);
	double getAngle();
	void lookAt(double, double);

private:
	sf::ConvexShape ray;
	sf::Vector2f pos;
	sf::Vector2f dir;
	double angle;
};

