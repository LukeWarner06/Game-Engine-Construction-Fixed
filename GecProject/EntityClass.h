#pragma once

#include <SFML/Graphics.hpp>
#include "RectangleCollision.h"

class EntityClass
{
public:
	// Gets the current position of the entity.
	sf::Vector2f GetPosition();

	// Sets the position of the entity to a new position.
	void SetPosition(sf::Vector2f newPosition);
	
	// Returns true or false if the entity is colliding with anything, read only.
	bool GetOverlappingState(const RectangleCollision& collision) const;

	// Read only getter that gets the entity's collider.
	const RectangleCollision& GetCollider() const;

private:
	// Sets the dinosaurs origin point to near the centre of its body.
	sf::Vector2f dinosaurOrigin = { 220, 420 };

	// Sets the default position of the dinosaur, this anchors the origin.
	sf::Vector2f dinosaurPosition = { 200, 520 };

	// This sets the offset of the collision box to fit around the dinosaurs actual body and not its sprite textures width and height.
	sf::Vector2f dinosaurBodyOffset{ 130, 40 };

	// Creates a visible outline of the dinosaurs collision box, containing its position minus the origin plus the offset.
	RectangleCollision dinosaurCollision{ { dinosaurPosition + (dinosaurBodyOffset - dinosaurOrigin) * 0.5f }, { 120, 190 } };
};

