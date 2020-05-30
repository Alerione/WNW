#ifndef __WNW_HorsesClass_
#define __WNW_HorsesClass_

#ifndef __WNW_BuildingClass_
#include "Building.h"
#endif

class Horses :
    public Building
{
public:
    Horses();
    Horses(const Horses& input);
    Horses(TileMap* input, Tile*, ResourceList*);
    virtual ~Horses();

    //Set and Get Methods//

    //Overloads//
    Horses& operator=(const Horses &input);

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
