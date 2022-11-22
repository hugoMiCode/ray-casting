#include "Ray.h"


Ray::Ray(sf::Vector2f pos, double angle)
{
	this->angle = angle;
	this->pos = pos;
	this->dir = sf::Vector2f(cos(angle * M_PI / 180) * 10, sin(angle * M_PI / 180) * 10);

	this->ray.setPointCount(4);
	this->ray.setPoint(0, pos);
	this->ray.setPoint(1, sf::Vector2f(this->pos.x + this->dir.x, this->pos.y + this->dir.y));
	this->ray.setPoint(2, sf::Vector2f(this->pos.x + this->dir.x, this->pos.y + this->dir.y));
	this->ray.setPoint(3, pos);
}

void Ray::show(sf::RenderWindow& window)
{
	sf::ConvexShape ray = this->ray;


	ray.setFillColor(sf::Color(168, 168, 168));
	ray.setOutlineThickness(2);
	ray.setOutlineColor(sf::Color(168, 168, 168));
	
	window.draw(ray);
}

sf::Vector2f Ray::cast(Boundray wall)
{
	double const x1 = wall.getPositionA().x;
	double const y1 = wall.getPositionA().y;
	double const x2 = wall.getPositionB().x;
	double const y2 = wall.getPositionB().y;

	double const x3 = this->pos.x;
	double const y3 = this->pos.y;
	double const x4 = (double)this->dir.x + this->pos.x; 
	double const y4 = (double)this->dir.y + this->pos.y;

	double det{ (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4) };

	if (det != 0) {
		double t{ ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / det };
		double u{ -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / det };

		if (t <= 1 && t >= 0 && u >= 0) {
			return sf::Vector2f(x1 + t * (x2 - x1), y1 + t * (y2 - y1));
		}
		else {
			return sf::Vector2f(0, 0);
		}
	}
	else {
		return sf::Vector2f(0, 0);
	}
}

double Ray::getAngle()
{
	return (this->angle);
}

void Ray::lookAt(double x, double y)
{
	this->dir.x = x;
	this->dir.y = y;
}