#include "Particle.h"

Particle::Particle(sf::RenderWindow& window, int _angle)
{
	this->pos = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

	for (double angle{ 0 }; angle < 360; angle += 1)
	{
		this->rays.push_back(Ray(this->pos, angle += _angle));
	}
}

void Particle::show(sf::RenderWindow& window)
{
	for (unsigned int i{ 0 }; i < this->rays.size(); i++)
	{
		this->rays[i].show(window);
	}
	sf::CircleShape particle(6);
	particle.setFillColor(sf::Color(168, 168, 168));
	particle.setPosition(pos.x - particle.getRadius(), pos.y - particle.getRadius());

	window.draw(particle);
}

void Particle::look(std::vector<Boundray>& walls, sf::RenderWindow& window)
{
	sf::Vector2f pt;
	sf::Vector2f closest(0, 0);
	sf::ConvexShape ray;
	ray.setPointCount(4);
	ray.setFillColor(sf::Color::White);
	ray.setOutlineThickness(1);
	ray.setOutlineColor(sf::Color(168, 168, 168));

	for (unsigned int i{ 0 }; i < this->rays.size(); i++) {
		double record{ INFINITY };

		for (unsigned int j{ 0 }; j < walls.size(); j++)
		{
			pt = this->rays[i].cast(walls[j]);

			if (pt != sf::Vector2f(0, 0)) {
				double d = dist(pt);
				if (d < record)
				{
					record = d;
					closest = pt;
				}
			}
		}
		if (closest != sf::Vector2f(0, 0)) {
			ray.setPoint(0, this->pos);
			ray.setPoint(1, closest);
			ray.setPoint(2, closest);
			ray.setPoint(3, this->pos);

			window.draw(ray);
		}
	}
}

void Particle::look1(Boundray& walls, sf::RenderWindow& window)
{
	sf::Vector2f pt;
	sf::ConvexShape ray;
	ray.setPointCount(4);
	ray.setFillColor(sf::Color::White);
	ray.setOutlineThickness(1);
	ray.setOutlineColor(sf::Color::White);


	for (unsigned int i{ 0 }; i < this->rays.size(); i++) {

		pt = this->rays[i].cast(walls);

		if (pt != sf::Vector2f(0, 0)) {
			ray.setPoint(0, this->pos);
			ray.setPoint(1, pt);
			ray.setPoint(2, pt);
			ray.setPoint(3, this->pos);

			window.draw(ray);
		}
	}
}

double Particle::dist(sf::Vector2f& pt)
{
	double x1 = pt.x;
	double y1 = pt.y;
	double x2 = this->pos.x;
	double y2 = this->pos.y;

	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void Particle::setPosition(double x, double y)
{
	this->pos.x = x;
	this->pos.y = y;
}