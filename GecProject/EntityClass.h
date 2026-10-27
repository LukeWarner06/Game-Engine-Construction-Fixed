#pragma once

#include <SFML/Graphics.hpp>
#include "RectangleCollision.h"

class EntityClass
{
public:



private:
	// Sets the dinosaurs origin point to near the centre of its body.
	sf::Vector2f dinosaurOrigin = { 220, 420 };

	// Sets the default position of the dinosaur, this anchors the origin.
	sf::Vector2f dinosaurPosition = { 400, 450 };

	// This sets the offset of the collision box to fit around the dinosaurs actual body and not its sprite textures width and height.
	sf::Vector2f dinosaurBodyOffset{ 130, 40 };

	// Creates a visible outline of the dinosaurs collision box, containing its position minus the origin plus the offset.
	RectangleCollision dinosaurCollision{ { dinosaurPosition - dinosaurOrigin + dinosaurBodyOffset }, { 240, 380 } };
};

