#ifndef __WNW_ResourceManagerClass_
#define __WNW_ResourceManagerClass_

#include "BuildingManager.h"
class ResourceManager
{
protected:
public:
	//Constructors and Destructors//
	ResourceManager();
	ResourceManager(BuildingManager *BManager);
	ResourceManager(const ResourceManager& org);
	~ResourceManager();
	BuildingManager* BManager;
	//Methods//
	void ResourceUpdateTick();
	ResourceList* GetResources();
	//Overloads//
	ResourceManager& operator=(const ResourceManager& input);

	ResourceList Resources;
protected:


};

#endif