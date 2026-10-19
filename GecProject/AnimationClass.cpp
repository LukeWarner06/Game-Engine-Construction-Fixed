#include "AnimationClass.h"

AnimationClass::AnimationClass(sf::Texture* texture, int width, int height, SpriteLayout spriteLayout)
{
	m_texture = texture;

	// Null texture pointers and zero/negative frame dimensions are rejected in order to prevent invalid calculations and sprite creation.
	if (m_texture == nullptr || width <= 0 || height <= 0)
	{
		//it failed to load, or was an invalid width or height.
	}

	else
	{
		sf::Vector2u textureXY = m_texture->getSize();

		// Frame dimensions are compared against the textures actual size in order to prevent frames from extending beyond the texture image.
		if (width > textureXY.x || height > textureXY.y)
		{
			return;
		}

		m_frameWidth = width;
		m_frameHeight = height;

		m_spriteOrientation = spriteLayout;

		switch (m_spriteOrientation)
		{
		case SpriteLayout::Horizontal:
			// The modulo checks whether the texture width divides evenly into complete frames, if not it returns early.
			if (textureXY.x % m_frameWidth != 0)
			{
				return;
			}
			m_frameCount = textureXY.x / m_frameWidth;
			break;
		case SpriteLayout::Vertical:
			// The modulo checks whether the texture height divides evenly into complete frames, if not it returns early.
			if (textureXY.y % m_frameHeight != 0)
			{
				return;
			}
			// The number of animation frames is a result of the texture dimensions, individual frame size and its orientation.
			m_frameCount = textureXY.y / m_frameHeight;
			break;
		}

		sf::IntRect rect({ 0, 0 }, { m_frameWidth, m_frameHeight });

		m_animatedRect = rect;

		// The sprite uses the supplied texture and displays the first frame, initially.
		m_animatedSprite = new sf::Sprite(*m_texture);
		m_animatedSprite->setTextureRect(m_animatedRect);
	}
}

// Releases the allocated sprite.
AnimationClass::~AnimationClass()
{
	delete(m_animatedSprite);
}

void AnimationClass::SetFrameDuration(sf::Time frameDuration)
{
	// Frame duration must be positive, if not it wont play animations.
	if (frameDuration > sf::Time::Zero)
	{
		m_frameDuration = frameDuration;
	}
}

// The frames advance if the current frame is greater than or equal to the frame count. It then returns to zero at the end and updates the displayed TextureRect.
void AnimationClass::NextFrame()
{
	if (m_animatedSprite == nullptr)
	{
		return;
	}

	m_currentFrame++;

	if (m_currentFrame >= m_frameCount)
	{
		m_currentFrame = 0;
	}

	switch (m_spriteOrientation)
	{
	case SpriteLayout::Horizontal:
		m_animatedRect.position.x = m_currentFrame * m_frameWidth;
		break;
	case SpriteLayout::Vertical:
		m_animatedRect.position.y = m_currentFrame * m_frameHeight;
		break;
	}

	m_animatedSprite->setTextureRect(m_animatedRect);
}

void AnimationClass::update(sf::Time dt)
{
	m_spriteTimer += dt;
	// Elapsed time accumulates and multiple frames can be advanced when necessary. This compensates for slower updates.
	while (m_spriteTimer >= m_frameDuration)
	{
		m_spriteTimer -= m_frameDuration;
		NextFrame();
	}
}

void AnimationClass::draw(sf::RenderWindow* window) const
{
	// The drawing of the sprite is skipped if the sprite was not successfully created.
	if (m_animatedSprite == nullptr)
	{
		return;
	}

	window->draw(*m_animatedSprite);
}

void AnimationClass::ResetFrameCount()
{
	m_currentFrame = 0;
	m_spriteTimer = sf::Time::Zero;
}

void AnimationClass::SetPosition(sf::Vector2f position)
{
	// This guard prevents any values being applied if the sprite is found to contain a null pointer.
	if (m_animatedSprite == nullptr)
	{
		return;
	}

	m_animatedSprite->setPosition(position);
}

void AnimationClass::SetOrigin(sf::Vector2f origin)
{
	// This guard prevents any values being applied if the sprite is found to contain a null pointer.
	if (m_animatedSprite == nullptr)
	{
		return;
	}

	m_animatedSprite->setOrigin(origin);
}
