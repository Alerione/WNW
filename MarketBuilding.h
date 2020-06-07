#ifndef __WNW_MarketBuildingClass_
#define __WNW_MarketBuildingClass_


#include "Building.h"
class MarketBuilding :
    public Building
{
public:
    MarketBuilding();
    MarketBuilding(const MarketBuilding& input);
    MarketBuilding(TileMap* input);
    virtual ~MarketBuilding();

    //Set and Get Methods//

    //Overloads//
    MarketBuilding& operator=(const MarketBuilding &input);

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