#include "TextureManager.h"
#include <utility>

bool TextureManager::LoadTexture(std::string textureName, std::string filePath)
{
	// Rejects duplicate texture names because textures with different graphics may have the same name, which would replace the existing one and disrupt the animation.
	// Rejecting them makes resource management in the project much more predictable.
	auto it = m_textureMap.find(textureName);
	if (it != m_textureMap.end())
	{
		return false;
	}

	else
	{
		// Loading the file into a tempTexture because it is safer. We want to ensure the texture has loaded successfully before adding it to the texture collection.
		// If the loading fails, the tempTexture is automatically destroyed and the texture collection remains unchanged.
		sf::Texture tempTexture;

		if (!tempTexture.loadFromFile(filePath))
		{
			return false;
		}
		// std::move allows the loaded texture to be transferred into the texture collection through the move assignment.
		// Moving it means the receiving object can take over the texture without making an unnecessary copy of it.
		m_textureMap[textureName] = std::move(tempTexture);

		return true;
	}

}

sf::Texture* TextureManager::GetTexture(std::string textureName)
{
	// Using a .find to search through the texture collection. This is preferable because it lets us check whether a texture exists without modifying the collection accidentally.
	auto it = m_textureMap.find(textureName);
	if (it != m_textureMap.end())
	{
		return &it->second;
	}

	return nullptr;
}