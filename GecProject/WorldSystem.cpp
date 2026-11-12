#include "WorldSystem.h"

void WorldSystem::AddObstacle(sf::Vector2f startingPosition, sf::Vector2f startingSize)
{
	m_obstacleCollection.emplace_back(startingPosition, startingSize);
}

void WorldSystem::DrawObstacles(GraphicsSystem& graphicsReference) const
{
	for (const auto& obstacle : m_obstacleCollection)
	{
		graphicsReference.DrawRectangle(obstacle.GetObstacle());
	}
}

bool WorldSystem::ObstacleCollision(const EntityClass& entityReference) const
{
	for (const auto& obstacle : m_obstacleCollection)
	{
		if (entityReference.GetOverlappingState(obstacle.GetObstacleCollision()))
		{
			return true;
		}
	}

	return false;
}