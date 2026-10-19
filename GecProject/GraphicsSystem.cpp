#include "GraphicsSystem.h"

// The render window reference is bound because reeference members must be initialised before the constructor body runs.
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
	// The windows address is passed to the animation. This is because the animation class expects a renderwindow pointer, while m_renderWindow is a reference to the window. &m_renderwindow then supplies that address of that existing window to match the parameter type.
	// This means the animation can then draw into it without copying or becoming its owner.
	animationClass.draw(&m_renderWindow);
}