#pragma once

#include <SFML/Graphics.hpp>

class MovementClass
{
public:
    MovementClass();

    void RequestJump();

private:
	sf::Vector2f m_dinosaurPosition = { 400, 450 };

    float m_groundedVerticalVelocity = 0.f;
    float m_currentVerticalVelocity = 0.f;
    float m_jumpVerticalVelocity = -600.f;

    float m_gravity = 2000.0f;

    float m_startingDinosaurY = m_dinosaurPosition.y;

    bool m_isGrounded = true;

    float m_dinosaurMovementSpeed = 150;
};