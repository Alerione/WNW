#ifndef __WNW_BuildingManagerClass_
#define __WNW_BuildingManagerClass_

#include "TavernBuilding.h"
#include "WellBuilding.h"
#include "StablesBuilding.h"
#include "SawmillBuilding.h"
#include "QuarryBuilding.h"
#include "BarracksBuilding.h"
#include "FarmBuilding.h"
#include "Tree.h"

class BuildingManager
{
protected:
public:
	//Constructors and Destructors//
	BuildingManager();
	BuildingManager(const BuildingManager& org);
	~BuildingManager();
	std::vector <Building*> BuildingsList;
	int BuildingNum;

	//Overloads//
	BuildingManager& operator=(const BuildingManager& input);

protected:

	
};

#endif