#ifndef __WNW_SchoolBuildingClass_
#define __WNW_SchoolBuildingClass_


#include "Building.h"
class SchoolBuilding :
    public Building
{
public:
    SchoolBuilding();
    SchoolBuilding(const SchoolBuilding& input);
    SchoolBuilding(TileMap* input);
    virtual ~SchoolBuilding();

    //Set and Get Methods//

    //Overloads//
    SchoolBuilding& operator=(const SchoolBuilding &input);

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