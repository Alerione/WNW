#ifndef __WNW_BuildingClass_
#define __WNW_BuildingClass_

#include <vector>

enum BuildingType {
	Unspecified = 0,
	Tavern = 1,
	Well = 2
};
struct BuildingDataDraw
{
	unsigned int BuildingSizeX;
	unsigned int BuildingSizeY;
	unsigned int SpriteOffsetX;
	unsigned int SpriteOffsetY;
};
struct BuildingDataGame
{

};

class Tile;
class Building
{
protected:
	//Variables//
	std::vector<std::vector<Tile>> *TileBase;
	BuildingType Type;
	BuildingDataDraw DrawData;
	BuildingDataGame GameData;

public:
	//Constructors and Destructors//
	Building();
	Building(const Building& input);
	virtual ~Building();

	//Set and Get Methods//

	//Overloads//
	Building& operator=(const Building &input);
};

#endif