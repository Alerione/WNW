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

sf::Texture & TextureManager::getCollisionTexture()
{
	return CollisionTexture;
}

sf::Texture & TextureManager::getWellTexture()
{
	return WellTexture;
}

sf::Texture & TextureManager::getBlueOverlayTexture()
{
	return BlueOverlayTexture;
}

sf::Texture & TextureManager::getStablesTexture()
{
	return StablesTexture;
}

sf::Texture& TextureManager::getInterfaceBuildButton()
{
    return InterfaceBuildButton;
}

sf::Texture& TextureManager::getMenuCat1Texture()
{
    return MenuCat1Texture;
}



TextureManager & TextureManager::operator=(const TextureManager & input)
{
	return *this;
}

void TextureManager::loadTextures()
{
	if(defaultTileTexture.loadFromFile("tile.png")) std::cout << "Tile texture loaded!" << std::endl;
	if(TavernTexture.loadFromFile("tavern.png")) std::cout << "Tavern texture loaded!" <<std::endl;
	if (StablesTexture.loadFromFile("stables.png")) std::cout << "Stables texture loaded!" << std::endl;
	if (CollisionTexture.loadFromFile("collision.png")) std::cout << "Collision texture loaded!" << std::endl;
	if (WellTexture.loadFromFile("well.png")) std::cout << "Well texture loaded!" << std::endl;
	if (BlueOverlayTexture.loadFromFile("blueoverlay.png")) std::cout << "Blue Overlay texture loaded!" << std::endl;
    if (InterfaceBuildButton.loadFromFile("build.png")) std::cout << "InterfaceBuildButton texture loaded!" << std::endl;
    if (MenuCat1Texture.loadFromFile("cat1.png")) std::cout << "Menu Cat1 Texture loaded!" << std::endl;
	std::cout << "Textures loaded!" << std::endl;
}


