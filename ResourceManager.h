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
	//Overloads//
	ResourceManager& operator=(const ResourceManager& input);

protected:


};

#endif