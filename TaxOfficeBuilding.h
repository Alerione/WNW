#ifndef __WNW_TaxOfficeBuildingClass_
#define __WNW_TaxOfficeBuildingClass_


#include "Building.h"
class TaxOfficeBuilding :
    public Building
{
public:
    TaxOfficeBuilding();
    TaxOfficeBuilding(const TaxOfficeBuilding& input);
    TaxOfficeBuilding(TileMap* input);
    virtual ~TaxOfficeBuilding();

    //Set and Get Methods//

    //Overloads//
    TaxOfficeBuilding& operator=(const TaxOfficeBuilding &input);

    //ResourceUpdateMethods//
    bool CheckResources();
    void ResourceUpdateTick();
    void BuildCost();
    void RemovalPass();

    //Methods//
    void SetupBuildingDatabyType();
    void DrawBuildingSpecific(sf::RenderWindow& target);

	//Building Specific Methods//
	int TaxArea();
};

#endif