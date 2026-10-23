#include "MovementClass.h"



MovementClass::MovementClass()
{

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
