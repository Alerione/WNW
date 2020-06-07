#ifndef __WNW_TheatreBuildingClass_
#define __WNW_TheatreBuildingClass_


#include "Building.h"
class TheatreBuilding :
    public Building
{
public:
    TheatreBuilding();
    TheatreBuilding(const TheatreBuilding& input);
    TheatreBuilding(TileMap* input);
    virtual ~TheatreBuilding();

    //Set and Get Methods//

    //Overloads//
    TheatreBuilding& operator=(const TheatreBuilding &input);

    //ResourceUpdateMethods//
    bool CheckResources();
    void ResourceUpdateTick();
    void BuildCost();
    void RemovalPass();

    //Methods//
    void SetupBuildingDatabyType();
    void DrawBuildingSpecific(sf::RenderWindow& target);

	//Building Specific Methods//
	void UpdateArea(bool);
};

#endif