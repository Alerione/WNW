#ifndef __WNW_BuildingClass_
#define __WNW_BuildingClass_

#include "TileMap.h"
#include "Structures.cpp"



enum BuildingType {
	Unspecified = 0,
	Tavern = 1,
	Well = 2,
	Stables = 3,
	Sawmill = 4,
	Quarry = 5,
	Barracks = 6,
	Farm = 7,
	Lumber = 8,
	ClayMine = 9,
	HorseBreeder = 10,
	House = 11,
	MerchantGuild = 12,
	MilitiaPost = 13,
	Fountain = 14,
	Jousting = 15,
    BrickMaker = 16,
    MarbleCutter = 17,
    Brewery = 18,
    Castle = 19,
    TaxOffice = 20,
    Market = 21,
    School = 22,
    University = 23,
    Doctor = 24,
    Hospital = 25,
    Theatre = 26,
    Horsess = 994,
    Marbles = 995,
    Clays = 996,
    Trees = 997
};
struct BuildingDataDraw
{
	bool Built;
	bool AutoDrawSprite;
	sf::Sprite Sprite;
	unsigned int BuildingSizeX;
	unsigned int BuildingSizeY;
	int SpriteOffsetX;
	int SpriteOffsetY;
};
struct BuildingDataGame
{
	bool WaterAccess;
	unsigned int Happiness;
	unsigned int Health;
	unsigned int PublicOrder;
	double ResourceMod;
	int PopReq;
};

class Building
{
protected:
	//Variables//
	std::vector<std::vector<Tile*>> TileBase;
	TileMap *Map;
	BuildingType Type;
	BuildingDataDraw DrawData;
	BuildingDataGame GameData;
	static bool BusyBuilding;
	static sf::Sprite CollisionSprite;
	static sf::Sprite BlueOverlaySprite;
	static bool StaticSpriteSet;
	ResourceList* Resources;

public:
	//Constructors and Destructors//
	Building();
	Building(const Building& input);
	virtual ~Building();

	//Set and Get Methods//
    BuildingDataGame& getDataGame();
	BuildingDataDraw& getDataDraw();

	//Overloads//
	Building& operator=(const Building &input);

	//Methods//
	BuildingType getType();
	ResourceList* getResources();
	bool CheckCollision(); // Is there Collision (True/False)
	void DrawCollision(sf::RenderTarget& target);
	void Build(ResourceList* Resources);
	void draw(sf::RenderWindow& target);
	void UpdatePositionbyMouse(sf::RenderWindow& target);
	static bool CheckBusy(); // Is  there enough resources (True/False)
	void UpdateBuildingGameData();
	int getPopReq();
	virtual bool CheckResources() = 0;
	virtual void SetupBuildingDatabyType() = 0;
	virtual void DrawBuildingSpecific(sf::RenderWindow& target) = 0;
	virtual void ResourceUpdateTick() = 0;
	virtual void BuildCost() = 0;
	virtual void RemovalPass() = 0;
	static bool sort(Building *a, Building *b)
	{
		if ((b->TileBase[0][0]->getID() % 256) > (a->TileBase[0][0]->getID() % 256)) return true;
		else if ((b->TileBase[0][0]->getID() % 256) < (a->TileBase[0][0]->getID() % 256)) return false;
		else if (b->TileBase[0][0]->getID() > a->TileBase[0][0]->getID()) return true;
		else return false;
	}
};


#endif