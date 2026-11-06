#include "MovementClass.h"



MovementClass::MovementClass(float dinosaurHeight)
{
	m_startingDinosaurY = dinosaurHeight;
}

void MovementClass::RequestJump()
{
	if (m_isGrounded)
	{
		m_isGrounded = false;
		m_currentVerticalVelocity = m_jumpVerticalVelocity;
	}
	else
	{

	}
}

sf::Vector2f MovementClass::MovementUpdate(sf::Vector2f currentPosition, sf::Vector2f direction, sf::Time elapsedTime)
{
	if (direction.length() > 0)
	{
		direction = direction.normalized();
		currentPosition += direction * m_dinosaurMovementSpeed * elapsedTime.asSeconds();
	}

	if (!m_isGrounded)
	{
		m_currentVerticalVelocity += m_gravity * elapsedTime.asSeconds();
		currentPosition.y += m_currentVerticalVelocity * elapsedTime.asSeconds();

		if (currentPosition.y >= m_startingDinosaurY)
		{
			currentPosition.y = m_startingDinosaurY;
			m_currentVerticalVelocity = m_groundedVerticalVelocity;
			m_isGrounded = true;
		}
	}

	return currentPosition;
}

bool MovementClass::GetGroundedState()
{
	return m_isGrounded;
}


