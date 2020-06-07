#ifndef __WNW_HospitalBuildingClass_
#define __WNW_HospitalBuildingClass_


#include "Building.h"
class HospitalBuilding :
    public Building
{
public:
    HospitalBuilding();
    HospitalBuilding(const HospitalBuilding& input);
    HospitalBuilding(TileMap* input);
    virtual ~HospitalBuilding();

    //Set and Get Methods//

    //Overloads//
    HospitalBuilding& operator=(const HospitalBuilding &input);

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