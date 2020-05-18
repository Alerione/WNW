#ifndef __WNW_LumberBuildingClass_
#define __WNW_LumberBuildingClass_


#include "Building.h"
class LumberBuilding :
	public Building
{
public:
	LumberBuilding();
	LumberBuilding(const LumberBuilding& input);
	LumberBuilding(TileMap* input);
	virtual ~LumberBuilding();

	//Set and Get Methods//

	//Overloads//
	LumberBuilding& operator=(const LumberBuilding &input);

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