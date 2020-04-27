#ifndef __WNW_WellBuildingClass_
#define __WNW_WellBuildingClass_


#include "Building.h"
class WellBuilding :
	public Building
{
public:
	WellBuilding();
	WellBuilding(const WellBuilding& input);
	WellBuilding(TileMap* input);
	virtual ~WellBuilding();

	//Set and Get Methods//

	//Overloads//
	WellBuilding& operator=(const WellBuilding &input);

	//ResourceUpdateMethods//
	void ResourceUpdateTick();
	void BuildCost();
	void RemovalPass();

	//Methods//
	void SetupBuildingDatabyType();
	void DrawBuildingSpecific(sf::RenderWindow& target);

	//Building Specific Methods//
	void UpdateArea(bool);
};

#endif