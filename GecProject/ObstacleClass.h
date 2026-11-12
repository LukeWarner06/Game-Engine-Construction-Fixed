#pragma once

#include <SFML/Graphics.hpp>
#include "RectangleCollision.h"

class ObstacleClass
{
public:
	ObstacleClass(sf::Vector2f initialPosition, sf::Vector2f initialSize);

	const sf::RectangleShape& GetObstacle() const;
	const RectangleCollision& GetObstacleCollision() const;

private:
	sf::RectangleShape m_obstacle;
	RectangleCollision rectCollision;
};

