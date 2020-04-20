#include "ResourceManager.h"



ResourceManager::ResourceManager()
	:BManager(nullptr)
{
}

ResourceManager::ResourceManager(BuildingManager * BManager)
	:BManager(BManager)
{
}

ResourceManager::ResourceManager(const ResourceManager & org)
	:BManager(org.BManager)
{
}


ResourceManager::~ResourceManager()
{
}

void ResourceManager::ResourceUpdateTick()
{
	for (int n = 0; n < BManager->BuildingNum; n++)
	{
		//BManager->BuildingsList[n].ResourceUpdateTick();
	}
}

ResourceManager & ResourceManager::operator=(const ResourceManager & input)
{
	if (this == &input) return *this;

	BManager = input.BManager;

	return *this;
}
