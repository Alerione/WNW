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

sf::Texture & TextureManager::getBackgroundTexture()
{
	return BackgroundTexture;
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

sf::Texture& TextureManager::getInterfaceStatsButton()
{
    return InterfaceStatsButton;
}

sf::Texture& TextureManager::getInterfaceMenuButton()
{
    return InterfaceMenuButton;
}

sf::Texture& TextureManager::getInterfaceDelButton()
{
    return InterfaceDelButton;
}

sf::Texture& TextureManager::getInterfaceCamButton()
{
    return InterfaceCamButton;
}

sf::Texture& TextureManager::getMenuCat1Texture()
{
    return MenuCat1Texture;
}

sf::Texture& TextureManager::getIeGoldTexture()
{
    return ieGold;
}

sf::Texture& TextureManager::getIeMarbleTexture()
{
    return ieMarble;
}

sf::Texture& TextureManager::getIePolishedMarbleTexture()
{
    return iePolishedMarble;
}

sf::Texture& TextureManager::getIeBricksTexture()
{
    return ieBricks;
}

sf::Texture& TextureManager::getIePlanksTexture()
{
    return iePlanks;
}

sf::Texture& TextureManager::getIeWoodTexture()
{
    return ieWood;
}

sf::Texture& TextureManager::getIeClayTexture()
{
    return ieClay;
}



TextureManager & TextureManager::operator=(const TextureManager & input)
{
	return *this;
}

void TextureManager::loadTextures()
{
	//Background//
	if (BackgroundTexture.loadFromFile("water.jpg")) { std::cout << "Background texture loaded!" << std::endl; BackgroundTexture.setRepeated(true); }
	//Tile//
	if(defaultTileTexture.loadFromFile("tile.png")) std::cout << "Tile texture loaded!" << std::endl;
	//Buildings//
	if(TavernTexture.loadFromFile("tavern.png")) std::cout << "Tavern texture loaded!" <<std::endl;
	if (StablesTexture.loadFromFile("stables.png")) std::cout << "Stables texture loaded!" << std::endl;
	if (WellTexture.loadFromFile("well.png")) std::cout << "Well texture loaded!" << std::endl;
	//Tile Overlays//
	if (CollisionTexture.loadFromFile("collision.png")) std::cout << "Collision texture loaded!" << std::endl;
	if (BlueOverlayTexture.loadFromFile("blueoverlay.png")) std::cout << "Blue Overlay texture loaded!" << std::endl;
	//Interface//
    if (InterfaceBuildButton.loadFromFile("build.png")) std::cout << "InterfaceBuildButton texture loaded!" << std::endl;
    if (InterfaceCamButton.loadFromFile("cam.png")) std::cout << "InterfaceCamButton texture loaded!" << std::endl;
    if (InterfaceMenuButton.loadFromFile("menu.png")) std::cout << "InterfaceMenuButton texture loaded!" << std::endl;
    if (InterfaceStatsButton.loadFromFile("stats.png")) std::cout << "InterfaceStatsButton texture loaded!" << std::endl;
    if (InterfaceDelButton.loadFromFile("del.png")) std::cout << "InterfaceDelButton texture loaded!" << std::endl;

    if (MenuCat1Texture.loadFromFile("cat1.png")) std::cout << "Menu Cat1 Texture loaded!" << std::endl;

    if (ieGold.loadFromFile("gold.png")) std::cout << "Gold Texture loaded!" << std::endl;
    if (ieBricks.loadFromFile("brick.png")) std::cout << "Bricks Texture loaded!" << std::endl;
    if (ieMarble.loadFromFile("marble2.png")) std::cout << "Marble2 Texture loaded!" << std::endl;
    if (iePolishedMarble.loadFromFile("marble1.png")) std::cout << "Marble1 Texture loaded!" << std::endl;
    if (ieWood.loadFromFile("wood.png")) std::cout << "Wood Texture loaded!" << std::endl;
    if (iePlanks.loadFromFile("planks.png")) std::cout << "Planks Texture loaded!" << std::endl;
    if (ieClay.loadFromFile("clay.png")) std::cout << "Clay Texture loaded!" << std::endl;

	std::cout << "Textures loaded!" << std::endl;
}