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
	sf::Texture BlueOverlayTexture;
	sf::Texture StablesTexture;
    sf::Texture InterfaceBuildButton;
    sf::Texture InterfaceDelButton;
    sf::Texture InterfaceStatsButton;
    sf::Texture InterfaceCamButton;
    sf::Texture InterfaceMenuButton;
    sf::Texture MenuCat1Texture;
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
	sf::Texture& getBlueOverlayTexture();
	sf::Texture& getStablesTexture();
    sf::Texture& getInterfaceBuildButton();
    sf::Texture& getMenuCat1Texture();
    sf::Texture& getInterfaceDelButton();
    sf::Texture& getInterfaceStatsButton();
    sf::Texture& getInterfaceCamButton();
    sf::Texture& getInterfaceMenuButton();

	//Overloads//
	TextureManager& operator=(const TextureManager& input);

protected:
	//Methods//
	void loadTextures();
};

#endif