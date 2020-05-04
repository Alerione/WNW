#ifndef __WNW_QuarryBuildingClass_
#define __WNW_QuarryBuildingClass_


#include "Building.h"
class QuarryBuilding :
	public Building
{
public:
	QuarryBuilding();
	QuarryBuilding(const QuarryBuilding& input);
	QuarryBuilding(TileMap* input);
	virtual ~QuarryBuilding();

	//Set and Get Methods//

	//Overloads//
	QuarryBuilding& operator=(const QuarryBuilding &input);

	//ResourceUpdateMethods//
	void ResourceUpdateTick();
	void BuildCost();
	void RemovalPass();

	//Methods//
	void SetupBuildingDatabyType();
	void DrawBuildingSpecific(sf::RenderWindow& target);
};

#endif