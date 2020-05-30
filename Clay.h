#ifndef __WNW_ClayClass_
#define __WNW_ClayClass_

#ifndef __WNW_BuildingClass_
#include "Building.h"
#endif

class Clay :
    public Building
{
public:
    Clay();
    Clay(const Clay& input);
    Clay(TileMap* input, Tile*, ResourceList*);
    virtual ~Clay();

    //Set and Get Methods//

    //Overloads//
    Clay& operator=(const Clay &input);

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
