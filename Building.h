#ifndef __WNW_BuildingClass_
#define __WNW_BuildingClass_

#include <vector>
#include "TileMap.h"
#include "TextureManager.h"

enum BuildingType {
	Unspecified = 0,
	Tavern = 1,
	Well = 2
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
	static bool CollisionSpriteSet;

public:
	//Constructors and Destructors//
	Building();
	Building(const Building& input);
	virtual ~Building();

	//Set and Get Methods//

	//Overloads//
	Building& operator=(const Building &input);
	bool operator<(const Building &input);

	//Methods//
	bool CheckCollision(); // Is there Collision (True/False)
	void DrawCollision(sf::RenderTarget& target);
	void Build();
	void draw(sf::RenderWindow& target);
	void UpdatePositionbyMouse(sf::RenderWindow& target);
	static bool CheckBusy();
	virtual void SetupBuildingDatabyType() = 0;
};


#endif