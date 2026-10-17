#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

// Manages the loading and storage of all textures. Identifies textures by storing them in a map that can be searched through. It is useful because without it, multiple copies of the same texture may be stored, allowing textures to be reused.
class TextureManager
{
public:
	// Checks if the specific textureName already exists in the map. 
	// if not, loads the file into a temporary Texture, if it succeeds, moves the texture into the map and stores the texture name, while returning true.
	// If the requested texture name already exists, or the file fails to load, it returns false.
	bool LoadTexture(std::string textureName, std::string filePath);

	// Searches m_textureMap using the given textureName. Returns a pointer to the existing texture, if the name is found. If not, returns nullptr.
	// TextureManager retains ownership.
	sf::Texture*  GetTexture(std::string textureName);

private:
	std::map<std::string, sf::Texture> m_textureMap;
};