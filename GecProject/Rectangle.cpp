#include "RectangleCollision.h"

RectangleCollision::RectangleCollision(sf::Vector2f position, sf::Vector2f size)
{
	// If the dimensions are negative, it leaves the object in it's default state rather than passing it the values.
	if (size.x < 0 || size.y < 0)
	{
		return;
	}

	m_rectanglePosition.x = position.x;
	m_rectanglePosition.y = position.y;

	m_rectangleSize.x = size.x;
	m_rectangleSize.y = size.y;
}

void RectangleCollision::SetCollisionPosition(sf::Vector2f collisionPosition)
{
	m_rectanglePosition = collisionPosition;
}

float RectangleCollision::GetRightEdge() const
{
	float rightEdge = m_rectanglePosition.x + m_rectangleSize.x;

	return rightEdge;
}

float RectangleCollision::GetBottomEdge() const
{
	float bottomEdge = m_rectanglePosition.y + m_rectangleSize.y;

	return bottomEdge;
}

bool RectangleCollision::Intersect(const RectangleCollision& rect) const
{
	// If either rectangle has no area, this prevents collision from occurrring.
	if (rect.m_rectangleSize.x <= 0 || rect.m_rectangleSize.y <= 0 || m_rectangleSize.x <= 0 || m_rectangleSize.y <= 0)
	{
		return false;
	}

	// Overlap is required on BOTH axes, with strict comparisons to exclude touching.
	if (GetRightEdge() > rect.m_rectanglePosition.x && rect.GetRightEdge() > m_rectanglePosition.x &&
		GetBottomEdge() > rect.m_rectanglePosition.y && rect.GetBottomEdge() > m_rectanglePosition.y)
	{
		return true;
	}

	else
	{
		return false;
	}
}


