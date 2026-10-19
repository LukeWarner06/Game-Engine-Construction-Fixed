#pragma once

#include <SFML/Graphics.hpp>
#include "AnimationClass.h"

class GraphicsSystem
{
public:
	GraphicsSystem(sf::RenderWindow& window);

	void BeginFrame();
	void EndFrame();

	void DrawRectangle(const sf::RectangleShape& rectangle);

	void DrawAnimation(const AnimationClass& animationClass);

private:
	sf::RenderWindow& m_renderWindow;
};

