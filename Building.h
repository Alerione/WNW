#ifndef __WNW_BuildingClass_
#define __WNW_BuildingClass_
enum BuildingType {
	Tavern = 1,
	Well = 2
};

class Tile;
class Building
{
protected:
	//Variables//
	Tile **TileBase;
	BuildingType Type;
	unsigned int BuildingSizeX;
	unsigned int BuildingSizeY;
	unsigned int SpriteOffsetX;
	unsigned int SpriteOffsetY;

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