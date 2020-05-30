#ifndef __WNW_HouseBuildingClass_
#define __WNW_HouseBuildingClass_


#include "Building.h"
class HouseBuilding :
	public Building
{
public:
	HouseBuilding();
	HouseBuilding(const HouseBuilding& input);
	HouseBuilding(TileMap* input);
	virtual ~HouseBuilding();

	//Set and Get Methods//

	//Overloads//
	HouseBuilding& operator=(const HouseBuilding &input);

	//ResourceUpdateMethods//
	bool CheckResources();
	void ResourceUpdateTick();
	void BuildCost();
	void RemovalPass();

	//Methods//
	void SetupBuildingDatabyType();
	void DrawBuildingSpecific(sf::RenderWindow& target);
};

#endif