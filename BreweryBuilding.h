#ifndef __WNW_BreweryBuildingClass_
#define __WNW_BreweryBuildingClass_


#include "Building.h"
class BreweryBuilding :
    public Building
{
public:
    BreweryBuilding();
    BreweryBuilding(const BreweryBuilding& input);
    BreweryBuilding(TileMap* input);
    virtual ~BreweryBuilding();

    //Set and Get Methods//

    //Overloads//
    BreweryBuilding& operator=(const BreweryBuilding &input);

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