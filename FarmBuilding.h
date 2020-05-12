#ifndef __WNW_FarmBuildingClass_
#define __WNW_FarmBuildingClass_


#include "Building.h"
class FarmBuilding :
	public Building
{
public:
	FarmBuilding();
	FarmBuilding(const FarmBuilding& input);
	FarmBuilding(TileMap* input);
	virtual ~FarmBuilding();
	sf::Sprite FarmSprite[4];
	int FarmGrowth;
	//Set and Get Methods//

	//Overloads//
	FarmBuilding& operator=(const FarmBuilding &input);

	//ResourceUpdateMethods//
	bool CheckResources();
	void ResourceUpdateTick();
	void BuildCost();
	void RemovalPass();

	//Methods//
	void SetupBuildingDatabyType();
	void DrawBuildingSpecific(sf::RenderWindow& target);

	//Building Specific Methods//
};

#endif