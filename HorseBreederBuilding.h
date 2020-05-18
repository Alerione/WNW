#ifndef __WNW_HorseBreederBuildingClass_
#define __WNW_HorseBreederBuildingClass_


#include "Building.h"
class HorseBreederBuilding :
	public Building
{
public:
	HorseBreederBuilding();
	HorseBreederBuilding(const HorseBreederBuilding& input);
	HorseBreederBuilding(TileMap* input);
	virtual ~HorseBreederBuilding();

	//Set and Get Methods//

	//Overloads//
	HorseBreederBuilding& operator=(const HorseBreederBuilding &input);

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