#ifndef __WNW_CastleBuildingClass_
#define __WNW_CastleBuildingClass_


#include "Building.h"
class CastleBuilding :
    public Building
{
public:
    CastleBuilding();
    CastleBuilding(const CastleBuilding& input);
    CastleBuilding(TileMap* input);
    virtual ~CastleBuilding();

    //Set and Get Methods//

    //Overloads//
    CastleBuilding& operator=(const CastleBuilding &input);

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