#ifndef __WNW_BuildingClass_
#define __WNW_BuildingClass_

#include <vector>
#include "TileMap.h"
#include "TextureManager.h"
#include "Structures.cpp"



enum BuildingType {
	Unspecified = 0,
	Tavern = 1,
	Well = 2,
	Stables = 3
};
struct BuildingDataDraw
{
	bool Built;
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

	//Overloads//
	Building& operator=(const Building &input);

	//Methods//
	bool CheckCollision(); // Is there Collision (True/False)
	void DrawCollision(sf::RenderTarget& target);
	void Build(ResourceList* Resources);
	void draw(sf::RenderWindow& target);
	void UpdatePositionbyMouse(sf::RenderWindow& target);
	static bool CheckBusy();
	bool CheckResources(); // Is  there enough resources (True/False)
	void UpdateBuildingGameData();
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