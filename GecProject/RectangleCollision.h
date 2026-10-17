#pragma once

#include "SFML/Graphics.hpp"

class RectangleCollision
{
public:
	RectangleCollision(sf::Vector2f position, sf::Vector2f size);

	void SetCollisionPosition(sf::Vector2f collisionPosition);

	bool Intersect(const RectangleCollision& rect) const;

	float GetRightEdge() const;
	float GetBottomEdge() const;

private:
	sf::Vector2f m_rectanglePosition{ 0, 0 };
	sf::Vector2f m_rectangleSize{ 0, 0 };
};