#ifndef __WNW_MarbleCutterBuildingClass_
#define __WNW_MarbleCutterBuildingClass_


#include "Building.h"
class MarbleCutterBuilding :
    public Building
{
public:
    MarbleCutterBuilding();
    MarbleCutterBuilding(const MarbleCutterBuilding& input);
    MarbleCutterBuilding(TileMap* input);
    virtual ~MarbleCutterBuilding();

    //Set and Get Methods//

    //Overloads//
    MarbleCutterBuilding& operator=(const MarbleCutterBuilding &input);

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