#include "BuildingManager.h"



BuildingManager::BuildingManager(SoundManager *s)
	: BuildingNum(0)
	, SManager(s)
{
	BuildingsList.resize(0);
}

BuildingManager::BuildingManager(const BuildingManager & org)
{
	SManager = org.SManager;
	BuildingNum = org.BuildingNum;
	BuildingsList = org.BuildingsList;

}


BuildingManager::~BuildingManager()
{
}

BuildingManager & BuildingManager::operator=(const BuildingManager & input)
{
	if (this == &input) return *this;

	BuildingNum = input.BuildingNum;
	BuildingsList = input.BuildingsList;

	return *this;
}
