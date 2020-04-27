#include "ResourceManager.h"



ResourceManager::ResourceManager()
	:BManager(nullptr)
	, Resources{}
{
}

ResourceManager::ResourceManager(BuildingManager * BManager)
	:BManager(BManager)
	, Resources{}
{
	Resources.Ducats = 1000;
	Resources.Bricks = 400;
	Resources.Planks = 400;
	Resources.Food = 1000;
}

ResourceManager::ResourceManager(const ResourceManager & org)
	:BManager(org.BManager)
	,Resources(org.Resources)
{
}


ResourceManager::~ResourceManager()
{
}

void ResourceManager::ResourceUpdateTick()
{
	for (int n = 0; n < BManager->BuildingNum; n++)
	{
		BManager->BuildingsList[n]->ResourceUpdateTick();
	}
	//HorseCapCheck();
	//PopulationCapCheck();
}

ResourceList * ResourceManager::GetResources()
{
	return &Resources;
}

ResourceManager & ResourceManager::operator=(const ResourceManager & input)
{
	if (this == &input) return *this;

	BManager = input.BManager;

	return *this;
}
