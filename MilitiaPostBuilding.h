#ifndef __WNW_MilitiaPostBuildingClass_
#define __WNW_MilitiaPostBuildingClass_


#include "Building.h"
class MilitiaPostBuilding :
	public Building
{
public:
	MilitiaPostBuilding();
	MilitiaPostBuilding(const MilitiaPostBuilding& input);
	MilitiaPostBuilding(TileMap* input);
	virtual ~MilitiaPostBuilding();

	//Set and Get Methods//

	//Overloads//
	MilitiaPostBuilding& operator=(const MilitiaPostBuilding &input);

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