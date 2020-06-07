#ifndef __WNW_TavernBuildingClass_
#define __WNW_TavernBuildingClass_

#include "Building.h"
class TavernBuilding :
	public Building
{
public:
	TavernBuilding();
	TavernBuilding(const TavernBuilding& input);
	TavernBuilding(TileMap* input);
	virtual ~TavernBuilding();

	//Set and Get Methods//

	//Overloads//
	TavernBuilding& operator=(const TavernBuilding &input);

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