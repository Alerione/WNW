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
	Resources.Prev_Ducats = 1000;
	Resources.Prev_Bricks = 400;
	Resources.Prev_Planks = 400;
	Resources.Prev_Food = 1000;
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
	RollOverPrev();
	for (int n = 0; n < BManager->BuildingNum; n++)
	{
		if(BManager->BuildingsList[n]->getResources()!=nullptr)BManager->BuildingsList[n]->ResourceUpdateTick();
	}
	//HorseCapCheck();
	//PopulationCapCheck();
	//ResourceCheck();
}

ResourceList * ResourceManager::GetResources()
{
	return &Resources;
}

void ResourceManager::RollOverPrev()
{
	Resources.Prev_Beer = Resources.Beer;
	Resources.Prev_Bricks = Resources.Bricks;
	Resources.Prev_Clay = Resources.Clay;
	Resources.Prev_Ducats = Resources.Ducats;
	Resources.Prev_Food = Resources.Food;
	Resources.Prev_Horses = Resources.Horses;
	Resources.Prev_Lumber = Resources.Lumber;
	Resources.Prev_Marble = Resources.Marble;
	Resources.Prev_MarbleBlocks = Resources.MarbleBlocks;
	Resources.Prev_Planks = Resources.Planks;
	Resources.Prev_Population = Resources.Population;
}

ResourceManager & ResourceManager::operator=(const ResourceManager & input)
{
	if (this == &input) return *this;

	BManager = input.BManager;

	return *this;
}
