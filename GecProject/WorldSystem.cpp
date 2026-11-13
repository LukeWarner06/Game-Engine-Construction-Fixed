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

sf::Vector2f WorldSystem::ResolveCollision(sf::Vector2f previousDinosaurPosition, sf::Vector2f newDinosaurPosition, const EntityClass& entityReference) const
{
	float xMovement = newDinosaurPosition.x - previousDinosaurPosition.x;
	float yMovement = newDinosaurPosition.y - previousDinosaurPosition.y;

	float newTopBound = entityReference.GetCollider().GetTopEdge() + yMovement;
	float newBottomBound = entityReference.GetCollider().GetBottomEdge() + yMovement;

	for (const auto& obstacle : m_obstacleCollection)
	{
		if (newBottomBound > obstacle.GetObstacleCollision().GetTopEdge() && newTopBound < obstacle.GetObstacleCollision().GetBottomEdge())
		{
			if (xMovement > 0 && entityReference.GetCollider().GetRightEdge() <= obstacle.GetObstacleCollision().GetLeftEdge() && entityReference.GetCollider().GetRightEdge() + xMovement > obstacle.GetObstacleCollision().GetLeftEdge())
			{
				float dinosaurOverlap = entityReference.GetCollider().GetRightEdge() + xMovement - obstacle.GetObstacleCollision().GetLeftEdge();
				newDinosaurPosition.x = newDinosaurPosition.x - dinosaurOverlap;
			}
		}
	}

	return sf::Vector2f(newDinosaurPosition);
}