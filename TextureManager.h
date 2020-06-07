#ifndef __WNW_TextureManagerClass_
#define __WNW_TextureManagerClass_

#include <vector>
#include <SFML/Graphics.hpp>

class TextureManager
{
protected:
	//BG//
	sf::Texture BackgroundTexture;
	sf::Texture WaterTexture;
	//Tiles//
	sf::Texture defaultTileTexture;
    sf::Texture defaultTileTexture1;
    sf::Texture defaultTileTexture2;
    sf::Texture defaultTileTexture3;
    sf::Texture defaultTileTexture4;
	//Buildings//
	sf::Texture TavernTexture;
	sf::Texture CollisionTexture;
	sf::Texture WellTexture;
	sf::Texture QuarryTexture;
	sf::Texture SawmillTexture;
	sf::Texture BlueOverlayTexture;
	sf::Texture StablesTexture;
	sf::Texture LumberTexture;
	sf::Texture ClayMineTexture;
	sf::Texture HorseBreederTexture;
	sf::Texture HouseTexture[2];
	sf::Texture MerchantGuildTexture;
	sf::Texture MilitiaPostTexture;
	sf::Texture FountainTexture;
	sf::Texture JoustingTexture;
    sf::Texture BrickMakerTexture;
    sf::Texture MarbleCutterTexture;
    sf::Texture BreweryTexture;
    sf::Texture CastleTexture;
    sf::Texture TaxOfficeTexture;
    sf::Texture MarketTexture;
    sf::Texture SchoolTexture;
    sf::Texture UniversityTexture;
    sf::Texture DoctorTexture;
    sf::Texture HospitalTexture;
    sf::Texture TheatreTexture;

	//Interface
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
	//Resources
    sf::Texture ieGold;
    sf::Texture ieMarble;
    sf::Texture iePolishedMarble;
    sf::Texture iePlanks;
    sf::Texture ieWood;
    sf::Texture ieBricks;
    sf::Texture ieClay;
	//Trees//
    sf::Texture treeTexture;
    sf::Texture treeTexture2;
    sf::Texture treeTexture3;
	//Farm//
    sf::Texture FarmTexture;
    sf::Texture FarmlandTexture[4];
    //Res//
    sf::Texture ClayTexture;
    sf::Texture MarbleTexture;
    sf::Texture HorsesTexture;

public:
	//Constructors and Destructors//
	TextureManager();
	TextureManager(const TextureManager& org);
	~TextureManager();

	//Texture getters//
	sf::Texture& getBackgroundTexture();
	sf::Texture& getWaterTexture();
	sf::Texture& getDefaultTileTexture();
    sf::Texture& getDefaultTileTexture1();
    sf::Texture& getDefaultTileTexture2();
    sf::Texture& getDefaultTileTexture3();
    sf::Texture& getDefaultTileTexture4();
	sf::Texture& getTavernTexture();
	sf::Texture& getCollisionTexture();
	sf::Texture& getWellTexture();
	sf::Texture& getQuarryTexture();
	sf::Texture& getSawmillTexture();
	sf::Texture& getLumberTexture();
	sf::Texture& getClayMineTexture();
	sf::Texture& getHorseBreederTexture();
	sf::Texture& getHouseTexture(int a = 0);
	sf::Texture& getMerchantGuildTexture();
	sf::Texture& getMilitiaPostTexture();
	sf::Texture& getFountainTexture();
	sf::Texture& getJoustingTexture();
    sf::Texture& getBrickMakerTexture();
    sf::Texture& getMarbleCutterTexture();
    sf::Texture& getBreweryTexture();
    sf::Texture& getCastleTexture();
    sf::Texture& getTaxOfficeTexutre();
    sf::Texture& getMarketTexture();
    sf::Texture& getSchoolTexture();
    sf::Texture& getUniversityTexture();
    sf::Texture& getDoctorTexture();
    sf::Texture& getHospitalTexture();
    sf::Texture& getTheatreTexture();

	sf::Texture& getBlueOverlayTexture();
	sf::Texture& getStablesTexture();
    sf::Texture& getBarracksTexture();

    sf::Texture& getFarmTexture();
    sf::Texture& getFarmlandTexture(int a = 0);

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

    sf::Texture& getTreeTexture();
    sf::Texture& getTreeTexture2();
    sf::Texture& getTreeTexture3();

    sf::Texture& getClayTexture();
    sf::Texture& getMarbleTexture();
    sf::Texture& getHorsesTexture();
   

	//Overloads//
	TextureManager& operator=(const TextureManager& input);

protected:
	//Methods//
	void loadTextures();
};

#endif