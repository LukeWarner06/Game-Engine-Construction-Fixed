#pragma once

#include <SFML/Graphics.hpp>

// To use to check whether the sprite sheet is animated in horizontal or vertical format.

enum class SpriteLayout
{
	Horizontal,
	Vertical
};

// Given a texture, one frame's size and layout, steps through the frames over a duration to animate it. It does not own the texture so the texture MUST outlive the object.
class AnimationClass
{
public:

	// Creates the sprite starting on the first frame. If the texture is nullptr, no sprite is made and nothing is drawn. The destructor deletes the sprite.
	AnimationClass(sf::Texture* texture, int width, int height, SpriteLayout spriteLayout);
	~AnimationClass();

	// Copying is disabled to prevent two animation objects from accidentally owning the same sprite pointer, which could potentially cause a double deletion.
	AnimationClass(const AnimationClass&) = delete;

	AnimationClass& operator=(const AnimationClass&) = delete;

	// Updates the sprite to the next frame based on the spriteTimer and elapsed time.
	void update(sf::Time dt);

	// Draws the sprite in the render window, without modifying the aniamtion state. Additionally, the window must be valid.
	void draw(sf::RenderWindow* window) const;

	// Sets how long the frame should last based on the frameDuration.
	void SetFrameDuration(sf::Time frameDuration);

	// Resets the frame counter to zero.
	void ResetFrameCount();

	// Sets window position to the sprite,
	void SetPosition(sf::Vector2f position);

	void SetOrigin(sf::Vector2f origin);

private:
	void NextFrame();

	// The texture is borrowed from the texture manage, compared to the animation which owns its sprite and is solely responsible for destroying it.
	sf::Texture* m_texture = nullptr;
	sf::Sprite* m_animatedSprite = nullptr;

	int m_currentFrame = 0;
	int m_frameCount = 0;

	int m_frameWidth = 0;
	int m_frameHeight = 0;

	// Track accumulated time and duration of each animations frame.
	sf::Time m_spriteTimer{ sf::Time::Zero };
	sf::Time m_frameDuration = sf::seconds(0.065f);
	
	// Rectangle for the texture region of the sprite.
	sf::IntRect m_animatedRect;

	SpriteLayout m_spriteOrientation = SpriteLayout::Vertical;
};