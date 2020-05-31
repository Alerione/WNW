#ifndef __WNW_JoustingBuildingClass_
#define __WNW_JoustingBuildingClass_

#include "Building.h"
class JoustingBuilding :
	public Building
{
public:
	JoustingBuilding();
	JoustingBuilding(const JoustingBuilding& input);
	JoustingBuilding(TileMap* input);
	virtual ~JoustingBuilding();

	//Set and Get Methods//

	//Overloads//
	JoustingBuilding& operator=(const JoustingBuilding &input);

	//ResourceUpdateMethods//
	bool CheckResources();
	void ResourceUpdateTick();
	void BuildCost();
	void RemovalPass();

	//Methods//
	void SetupBuildingDatabyType();
	void DrawBuildingSpecific(sf::RenderWindow& target);

	//Building Specific Methods//
	void UpdateArea();
};

#endif