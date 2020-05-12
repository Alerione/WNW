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

sf::Texture & TextureManager::getDefaultTileTexture1()
{
    return defaultTileTexture1;
}

sf::Texture & TextureManager::getDefaultTileTexture2()
{
	return defaultTileTexture2;
}

sf::Texture & TextureManager::getDefaultTileTexture3()
{
    return defaultTileTexture3;
}

sf::Texture & TextureManager::getDefaultTileTexture4()
{
    return defaultTileTexture4;
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

sf::Texture & TextureManager::getQuarryTexture()
{
	return QuarryTexture;
}

sf::Texture & TextureManager::getSawmillTexture()
{
	return SawmillTexture;
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

sf::Texture& TextureManager::getMenuCat2Texture()
{
    return MenuCat2Texture;
}

sf::Texture& TextureManager::getIeBgTexture()
{
    return ieBg;
}

sf::Texture& TextureManager::getIeBg2Texture()
{
    return ieBg2;
}

sf::Texture& TextureManager::getIeBg3Texture()
{
    return ieBg3;
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

sf::Texture& TextureManager::getBarracksTexture()
{
    return BarracksTexture;
}

sf::Texture& TextureManager::getTreeTexture()
{
    return treeTexture;
}
sf::Texture& TextureManager::getTreeTexture2()
{
    return treeTexture2;
}
sf::Texture& TextureManager::getTreeTexture3()
{
    return treeTexture3;
}

sf::Texture & TextureManager::getFarmTexture()
{
    return FarmTexture;
}

sf::Texture & TextureManager::getFarmlandTexture(int a)
{
    return FarmlandTexture[a];
}

TextureManager & TextureManager::operator=(const TextureManager & input)
{
	return *this;
}

void TextureManager::loadTextures()
{
	//Background//
	if (BackgroundTexture.loadFromFile("bgmap.jpg")) { std::cout << "Background texture loaded!" << std::endl; BackgroundTexture.setRepeated(true); }
	//Tile//
	if(defaultTileTexture.loadFromFile("tile.png")) std::cout << "Tile texture loaded!" << std::endl;
    if (defaultTileTexture1.loadFromFile("tilenull.png")) std::cout << "Tile1 texture loaded!" << std::endl;
    if (defaultTileTexture2.loadFromFile("tile2.png")) std::cout << "Tile2 texture loaded!" << std::endl;
    if (defaultTileTexture3.loadFromFile("tile3.png")) std::cout << "Tile3 texture loaded!" << std::endl;
    if (defaultTileTexture4.loadFromFile("tile4.png")) std::cout << "Tile4 texture loaded!" << std::endl;

	//Buildings//
	if(TavernTexture.loadFromFile("tavern.png")) std::cout << "Tavern texture loaded!" <<std::endl;
	if (StablesTexture.loadFromFile("stables.png")) std::cout << "Stables texture loaded!" << std::endl;
	if (WellTexture.loadFromFile("well.png")) std::cout << "Well texture loaded!" << std::endl;
	if (QuarryTexture.loadFromFile("quarry.png")) std::cout << "Quarry texture loaded!" << std::endl;
	if (SawmillTexture.loadFromFile("sawmill.png")) std::cout << "Sawmill texture loaded!" << std::endl;
    if (BarracksTexture.loadFromFile("barracks.png")) std::cout << "Barracks texture loaded!" << std::endl;
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
    if (MenuCat2Texture.loadFromFile("cat2.png")) std::cout << "Menu Cat2 Texture loaded!" << std::endl;

    if (ieBg.loadFromFile("bg.png")) std::cout << "bg Texture loaded!" << std::endl;
    ieBg.setRepeated(1);
    if (ieBg2.loadFromFile("bg2.png")) std::cout << "bg2 Texture loaded!" << std::endl;
    ieBg2.setRepeated(1);
    if (ieBg3.loadFromFile("bg3.jpg")) std::cout << "bg3 Texture loaded!" << std::endl;
    ieBg2.setRepeated(1);

    if (ieGold.loadFromFile("gold.png")) std::cout << "Gold Texture loaded!" << std::endl;
    if (ieBricks.loadFromFile("brick.png")) std::cout << "Bricks Texture loaded!" << std::endl;
    if (ieMarble.loadFromFile("marble2.png")) std::cout << "Marble2 Texture loaded!" << std::endl;
    if (iePolishedMarble.loadFromFile("marble1.png")) std::cout << "Marble1 Texture loaded!" << std::endl;
    if (ieWood.loadFromFile("wood.png")) std::cout << "Wood Texture loaded!" << std::endl;
    if (iePlanks.loadFromFile("planks.png")) std::cout << "Planks Texture loaded!" << std::endl;
    if (ieClay.loadFromFile("clay.png")) std::cout << "Clay Texture loaded!" << std::endl;

    if (treeTexture.loadFromFile("tree.png")) std::cout << "Tree Texture loaded!" << std::endl;
    if (treeTexture2.loadFromFile("tree2.png")) std::cout << "Tree Texture loaded!" << std::endl;
    if (treeTexture3.loadFromFile("tree3.png")) std::cout << "Tree Texture loaded!" << std::endl;

    if (FarmTexture.loadFromFile("farm.png")) std::cout << "Farm texture loaded!" << std::endl;
    //Terrain Features//
    {
        bool f = false;
        if (FarmlandTexture[0].loadFromFile("farmland0.png"))
        {
            std::cout << "Farmland textures loaded.. 1";
            f = true;
        }

        if (FarmlandTexture[1].loadFromFile("farmland1.png"))
        {
            if (!f)
            {
                std::cout << "Farmland textures loaded.. 2";
                f = true;
            }
            else
            {
                std::cout << ".. 2";
            }
        }

        if (FarmlandTexture[2].loadFromFile("farmland2.png"))
        {
            if (!f)
            {
                std::cout << "Farmland textures loaded.. 3";
                f = true;
            }
            else
            {
                std::cout << ".. 3";
            }
        }

        if (FarmlandTexture[3].loadFromFile("farmland3.png"))
        {
            if (!f)
            {
                std::cout << "Farmland textures loaded.. 4";
                f = true;
            }
            else
            {
                std::cout << ".. 4";
            }
        }
        std::cout << "!" << std::endl;
    }

	std::cout << "Textures loaded!" << std::endl;
}