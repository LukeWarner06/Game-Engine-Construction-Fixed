#pragma once

#include "SFML/Graphics.hpp"

// Not pixel perfect collision. Instead, uses Axis aligned geometry which detects collision rather than a collision response.
class RectangleCollision
{
public:
	// Sets the private variables to the values of the constructors. Does not pass values if their sizes are invalid.
	RectangleCollision(sf::Vector2f position, sf::Vector2f size);

	// Sets the position of the collision, which changes independently of it's size.
	void SetCollisionPosition(sf::Vector2f collisionPosition);

	// Collision occurs when objects overlap or intersect rather than just simply touching, without modifying either object involved, just reading.
	bool Intersect(const RectangleCollision& rect) const;

	// Edges calculated from current information.
	float GetRightEdge() const;
	float GetBottomEdge() const;

private:
	// Rectangle position points to the top left corner, size includes width and height.
	sf::Vector2f m_rectanglePosition{ 0, 0 };
	sf::Vector2f m_rectangleSize{ 0, 0 };
};