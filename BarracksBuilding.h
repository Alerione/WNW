#ifndef __WNW_BarracksBuildingClass_
#define __WNW_BarracksBuildingClass_


#include "Building.h"
class BarracksBuilding :
	public Building
{
public:
	BarracksBuilding();
	BarracksBuilding(const BarracksBuilding& input);
	BarracksBuilding(TileMap* input);
	virtual ~BarracksBuilding();

	//Set and Get Methods//

	//Overloads//
	BarracksBuilding& operator=(const BarracksBuilding &input);

	//ResourceUpdateMethods//
	bool CheckResources();
	void ResourceUpdateTick();
	void BuildCost();
	void RemovalPass();

	//Methods//
	void SetupBuildingDatabyType();
	void DrawBuildingSpecific(sf::RenderWindow& target);
	void UpdateArea(bool);
};

#endif