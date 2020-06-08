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
#include "BrickMakerBuilding.h"
#include "MarbleCutterBuilding.h"
#include "BreweryBuilding.h"
#include "CastleBuilding.h"
#include "TaxOfficeBuilding.h"
#include "MarketBuilding.h"
#include "SchoolBuilding.h"
#include "UniversityBuilding.h"
#include "DoctorBuilding.h"
#include "HospitalBuilding.h"
#include "TheatreBuilding.h"


//Features//
#include "Tree.h"
#include "Clay.h"
#include "Marble.h"
#include "Horses.h"

//Sound//
#include "SoundManager.h"

class BuildingManager
{
protected:
public:
	//Constructors and Destructors//
	BuildingManager(SoundManager*);
	BuildingManager(const BuildingManager& org);
	~BuildingManager();
	std::vector <Building*> BuildingsList;
	int BuildingNum;
	SoundManager *SManager;

	//Overloads//
	BuildingManager& operator=(const BuildingManager& input);

protected:

	
};

#endif