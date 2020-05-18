#ifndef __WNW_ClayMineBuildingClass_
#define __WNW_ClayMineBuildingClass_


#include "Building.h"
class ClayMineBuilding :
	public Building
{
public:
	ClayMineBuilding();
	ClayMineBuilding(const ClayMineBuilding& input);
	ClayMineBuilding(TileMap* input);
	virtual ~ClayMineBuilding();

	//Set and Get Methods//

	//Overloads//
	ClayMineBuilding& operator=(const ClayMineBuilding &input);

	//ResourceUpdateMethods//
	bool CheckResources();
	void ResourceUpdateTick();
	void BuildCost();
	void RemovalPass();

	//Methods//
	void SetupBuildingDatabyType();
	void DrawBuildingSpecific(sf::RenderWindow& target);

	//Building Specific Methods//
	int FarmArea();
};

#endif