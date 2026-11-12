#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "ObstacleClass.h"
#include "GraphicsSystem.h"
#include "EntityClass.h"

class WorldSystem
{
public:
	void AddObstacle(sf::Vector2f startingPosition, sf::Vector2f startingSize);
	void DrawObstacles(GraphicsSystem& graphicsReference) const;

	bool ObstacleCollision(const EntityClass& entityReference) const;

private:
	std::vector<ObstacleClass> m_obstacleCollection;
};