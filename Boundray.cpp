#include "Boundray.h"


Boundray::Boundray(double x1, double y1, double x2, double y2)
{
	this->a = sf::Vector2f(x1, y1);
	this->b = sf::Vector2f(x2, y2);

	this->wall.setPointCount(4);
	this->wall.setPoint(0, a);
	this->wall.setPoint(1, b);
	this->wall.setPoint(2, b);
	this->wall.setPoint(3, a);

}

void Boundray::show(sf::RenderWindow& window)
{
	sf::ConvexShape wall{ this->wall };
	wall.setOutlineThickness(2);
	wall.setOutlineColor(sf::Color::White);
	wall.setFillColor(sf::Color::White);

	window.draw(wall);
}

sf::Vector2f Boundray::getPositionA()
{
	return sf::Vector2f(this->a.x, this->a.y);
}

sf::Vector2f Boundray::getPositionB()
{
	return sf::Vector2f(this->b.x, this->b.y);
}