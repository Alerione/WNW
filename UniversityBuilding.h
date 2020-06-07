#ifndef __WNW_UniversityBuildingClass_
#define __WNW_UniversityBuildingClass_


#include "Building.h"
class UniversityBuilding :
    public Building
{
public:
    UniversityBuilding();
    UniversityBuilding(const UniversityBuilding& input);
    UniversityBuilding(TileMap* input);
    virtual ~UniversityBuilding();

    //Set and Get Methods//

    //Overloads//
    UniversityBuilding& operator=(const UniversityBuilding &input);

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