#ifndef __WNW_MarbleClass_
#define __WNW_MarbleClass_

#ifndef __WNW_BuildingClass_
#include "Building.h"
#endif

class Marble :
    public Building
{
public:
    Marble();
    Marble(const Marble& input);
    Marble(TileMap* input, Tile*, ResourceList*);
    virtual ~Marble();

    //Set and Get Methods//

    //Overloads//
    Marble& operator=(const Marble &input);

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
