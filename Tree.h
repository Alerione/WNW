#ifndef __WNW_TreeClass_
#define __WNW_TreeClass_

#ifndef __WNW_BuildingClass_
#include "Building.h"
#endif

class Tree :
    public Building
{
public:
    Tree();
    Tree(const Tree& input);
    Tree(TileMap* input, Tile*, ResourceList*);
    virtual ~Tree();

    //Set and Get Methods//

    //Overloads//
    Tree& operator=(const Tree &input);

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
