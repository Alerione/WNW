#ifndef __WNW_BuildingManagerClass_
#define __WNW_BuildingManagerClass_

//Buildings//
#include "TavernBuilding.h"
#include "WellBuilding.h"
#include "StablesBuilding.h"
#include "SawmillBuilding.h"
#include "QuarryBuilding.h"
#include "BarracksBuilding.h"
#include "FarmBuilding.h"
#include "LumberBuilding.h"
#include "ClayMineBuilding.h"
#include "HorseBreederBuilding.h"
#include "HouseBuilding.h"
#include "MerchantGuildBuilding.h"
#include "MilitiaPostBuilding.h"
#include "FountainBuilding.h"
#include "JoustingBuilding.h"
//Features//
#include "Tree.h"
#include "Clay.h"
#include "Marble.h"
#include "Horses.h"

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