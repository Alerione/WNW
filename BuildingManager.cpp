#include "BuildingManager.h"



BuildingManager::BuildingManager()
	: BuildingNum(0)
{
	BuildingsList.resize(0);
}

BuildingManager::BuildingManager(const BuildingManager & org)
{

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
