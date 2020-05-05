#ifndef __WNW_SawmillBuildingClass_
#define __WNW_SawmillBuildingClass_


#include "Building.h"
class SawmillBuilding :
	public Building
{
public:
	SawmillBuilding();
	SawmillBuilding(const SawmillBuilding& input);
	SawmillBuilding(TileMap* input);
	virtual ~SawmillBuilding();

	//Set and Get Methods//

	//Overloads//
	SawmillBuilding& operator=(const SawmillBuilding &input);

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