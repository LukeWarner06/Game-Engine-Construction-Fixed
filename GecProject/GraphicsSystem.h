#pragma once

#include <SFML/Graphics.hpp>
#include "AnimationClass.h"

// Clearing the window, displaying the window, and Drawing any shapes and animations.
class GraphicsSystem
{
public:
	// Borrowing the window so we do not have to make multiple of it, and can just reference the existing window instead.
	GraphicsSystem(sf::RenderWindow& window);

	// Begin Frame because it clears the window ready for everything else to be drawn, called before anything is drawn so remaining objects are cleared.
	void BeginFrame();
	// Presents the frame, called after the window is cleared.
	void EndFrame();

	// Draws an existing rectangle without owning or copying it.
	void DrawRectangle(const sf::RectangleShape& rectangle);

	// Draws the animation while keeping the sprite private within its class.
	void DrawAnimation(const AnimationClass& animationClass);

private:
	// This is a stored reference to the render window, so that it's ownership stays somewhere else.
	sf::RenderWindow& m_renderWindow;
};

