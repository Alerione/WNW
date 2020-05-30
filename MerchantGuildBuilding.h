#ifndef __WNW_MerchantGuildBuildingClass_
#define __WNW_MerchantGuildBuildingClass_


#include "Building.h"
class MerchantGuildBuilding :
	public Building
{
public:
	MerchantGuildBuilding();
	MerchantGuildBuilding(const MerchantGuildBuilding& input);
	MerchantGuildBuilding(TileMap* input);
	virtual ~MerchantGuildBuilding();

	//Set and Get Methods//

	//Overloads//
	MerchantGuildBuilding& operator=(const MerchantGuildBuilding &input);

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