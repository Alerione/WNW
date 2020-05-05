#ifndef __WNW_TextureManagerClass_
#define __WNW_TextureManagerClass_

#include <vector>
#include <SFML/Graphics.hpp>

class TextureManager
{
protected:
	sf::Texture BackgroundTexture;
	sf::Texture defaultTileTexture;
	sf::Texture TavernTexture;
	sf::Texture CollisionTexture;
	sf::Texture WellTexture;
	sf::Texture QuarryTexture;
	sf::Texture SawmillTexture;
	sf::Texture BlueOverlayTexture;
	sf::Texture StablesTexture;
    sf::Texture InterfaceBuildButton;
    sf::Texture InterfaceDelButton;
    sf::Texture InterfaceStatsButton;
    sf::Texture InterfaceCamButton;
    sf::Texture InterfaceMenuButton;
    sf::Texture BarracksTexture;
    
    sf::Texture MenuCat1Texture;
    sf::Texture MenuCat2Texture;

    sf::Texture ieBg;
    sf::Texture ieBg2;
    sf::Texture ieBg3;

    sf::Texture ieGold;
    sf::Texture ieMarble;
    sf::Texture iePolishedMarble;
    sf::Texture iePlanks;
    sf::Texture ieWood;
    sf::Texture ieBricks;
    sf::Texture ieClay;
public:
	//Constructors and Destructors//
	TextureManager();
	TextureManager(const TextureManager& org);
	~TextureManager();

	//Texture getters//
	sf::Texture& getBackgroundTexture();
	sf::Texture& getDefaultTileTexture();
	sf::Texture& getTavernTexture();
	sf::Texture& getCollisionTexture();
	sf::Texture& getWellTexture();
	sf::Texture& getQuarryTexture();
	sf::Texture& getSawmillTexture();
	sf::Texture& getBlueOverlayTexture();
	sf::Texture& getStablesTexture();
    sf::Texture& getBarracksTexture();
    sf::Texture& getInterfaceBuildButton();

    sf::Texture& getMenuCat1Texture();
    sf::Texture& getMenuCat2Texture();

    sf::Texture& getIeBgTexture();
    sf::Texture& getIeBg2Texture();
    sf::Texture& getIeBg3Texture();

    sf::Texture& getInterfaceDelButton();
    sf::Texture& getInterfaceStatsButton();
    sf::Texture& getInterfaceCamButton();
    sf::Texture& getInterfaceMenuButton();
    sf::Texture& getIeGoldTexture();
    sf::Texture& getIeWoodTexture();
    sf::Texture& getIePlanksTexture();
    sf::Texture& getIeBricksTexture();
    sf::Texture& getIeMarbleTexture();
    sf::Texture& getIePolishedMarbleTexture();
    sf::Texture& getIeClayTexture();
   

	//Overloads//
	TextureManager& operator=(const TextureManager& input);

protected:
	//Methods//
	void loadTextures();
};

#endif