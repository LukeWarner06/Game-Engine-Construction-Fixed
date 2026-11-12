#include "EntityClass.h"

sf::Vector2f EntityClass::GetPosition()
{
    return dinosaurPosition;
}

void EntityClass::SetPosition(sf::Vector2f newPosition)
{
    dinosaurPosition = newPosition;
    dinosaurCollision.SetCollisionPosition(newPosition - dinosaurOrigin + dinosaurBodyOffset);
}

bool EntityClass::GetOverlappingState(const RectangleCollision& collision) const
{
    return dinosaurCollision.Intersect(collision);
}