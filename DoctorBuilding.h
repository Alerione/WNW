#ifndef __WNW_DoctorBuildingClass_
#define __WNW_DoctorBuildingClass_


#include "Building.h"
class DoctorBuilding :
    public Building
{
public:
    DoctorBuilding();
    DoctorBuilding(const DoctorBuilding& input);
    DoctorBuilding(TileMap* input);
    virtual ~DoctorBuilding();

    //Set and Get Methods//

    //Overloads//
    DoctorBuilding& operator=(const DoctorBuilding &input);

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