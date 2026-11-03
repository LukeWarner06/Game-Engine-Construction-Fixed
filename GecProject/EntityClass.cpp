#include "EntityClass.h"

sf::Vector2f EntityClass::GetPosition()
{
    return dinosaurPosition;
}

void EntityClass::SetPosition(sf::Vector2f newPosition)
{
    dinosaurPosition = newPosition;
}


