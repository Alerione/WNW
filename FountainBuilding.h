#ifndef __WNW_FountainBuildingClass_
#define __WNW_FountainBuildingClass_


#include "Building.h"
class FountainBuilding :
	public Building
{
public:
	FountainBuilding();
	FountainBuilding(const FountainBuilding& input);
	FountainBuilding(TileMap* input);
	virtual ~FountainBuilding();

	//Set and Get Methods//

	//Overloads//
	FountainBuilding& operator=(const FountainBuilding &input);

	//ResourceUpdateMethods//
	bool CheckResources();
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