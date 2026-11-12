#include "ObstacleClass.h"

ObstacleClass::ObstacleClass(sf::Vector2f initialPosition, sf::Vector2f initialSize) : rectCollision(initialPosition, initialSize)
{
	m_obstacle.setPosition(initialPosition);
	m_obstacle.setSize(initialSize);
}

const sf::RectangleShape& ObstacleClass::GetObstacle() const
{
	return m_obstacle;
}

const RectangleCollision& ObstacleClass::GetObstacleCollision() const
{
	return rectCollision;
}