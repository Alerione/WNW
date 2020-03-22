#include "TextureManager.h"
#include <iostream>


TextureManager::TextureManager()
{
	std::cout << "Texture Manager created!" << std::endl;
	loadTextures();
}

TextureManager::TextureManager(const TextureManager & org)
{
	std::cout << "Texture Manager created!" << std::endl;
	loadTextures();
}


TextureManager::~TextureManager()
{
}

sf::Texture & TextureManager::getDefaultTileTexture()
{
	return defaultTileTexture;
}

sf::Texture & TextureManager::getTavernTexture()
{
	return TavernTexture;
}

TextureManager & TextureManager::operator=(const TextureManager & input)
{
	return *this;
}

void TextureManager::loadTextures()
{
	if(defaultTileTexture.loadFromFile("tile.png")) std::cout << "Tile texture loaded!" << std::endl;
	if(TavernTexture.loadFromFile("tavern.png")) std::cout << "Tavern texture loaded!" <<std::endl;
	std::cout << "Textures loaded!" << std::endl;
}
