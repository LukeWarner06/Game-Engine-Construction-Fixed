#include "GraphicsSystem.h"

GraphicsSystem::GraphicsSystem(sf::RenderWindow& window) : m_renderWindow(window)
{

}

void GraphicsSystem::BeginFrame()
{
	m_renderWindow.clear();
}

void GraphicsSystem::EndFrame()
{
	m_renderWindow.display();
}

void GraphicsSystem::DrawRectangle(const sf::RectangleShape& rectangle)
{
	m_renderWindow.draw(rectangle);
}

void GraphicsSystem::DrawAnimation(const AnimationClass& animationClass)
{
	animationClass.draw(&m_renderWindow);
}



