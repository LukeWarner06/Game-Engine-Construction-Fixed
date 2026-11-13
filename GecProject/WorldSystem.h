#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "ObstacleClass.h"
#include "GraphicsSystem.h"
#include "EntityClass.h"

class WorldSystem
{
public:
	// Adds an obstacle to the stored collection of obstacles.
	void AddObstacle(sf::Vector2f startingPosition, sf::Vector2f startingSize);
	// Draws the obstacle specified when calling it from the collection
	void DrawObstacles(GraphicsSystem& graphicsReference) const;

	// Read only check to return true or false if the obstacle is colliding with anything.
	bool ObstacleCollision(const EntityClass& entityReference) const;

	// Resolves any collision between entities and obstacles, this is used before setting the new position of the entity moving to check whether it is colliding with something.
	sf::Vector2f ResolveCollision(sf::Vector2f previousDinosaurPosition, sf::Vector2f newDinosaurPosition, const EntityClass& entityReference) const;

private:
	// Collection of obstacle stored in a vector.
	std::vector<ObstacleClass> m_obstacleCollection;
};