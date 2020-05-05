#ifndef __WNW_StablesBuildingClass_
#define __WNW_StablesBuildingClass_


#include "Building.h"
class StablesBuilding :
	public Building
{
public:
	StablesBuilding();
	StablesBuilding(const StablesBuilding& input);
	StablesBuilding(TileMap* input);
	virtual ~StablesBuilding();

	//Set and Get Methods//

	//Overloads//
	StablesBuilding& operator=(const StablesBuilding &input);

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