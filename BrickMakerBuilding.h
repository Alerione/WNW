#ifndef __WNW_BrickMakerBuildingClass_
#define __WNW_BrickMakerBuildingClass_


#include "Building.h"
class BrickMakerBuilding :
    public Building
{
public:
    BrickMakerBuilding();
    BrickMakerBuilding(const BrickMakerBuilding& input);
    BrickMakerBuilding(TileMap* input);
    virtual ~BrickMakerBuilding();

    //Set and Get Methods//

    //Overloads//
    BrickMakerBuilding& operator=(const BrickMakerBuilding &input);

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