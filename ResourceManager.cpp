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
	Resources.Ducats = Resources.Prev_Ducats = 1000;
	Resources.Bricks = Resources.Prev_Bricks = 400;
	Resources.Planks = Resources.Prev_Planks = 400;
	Resources.Lumber = Resources.Prev_Lumber = 400;
	Resources.Food = Resources.Prev_Food = 1000;
	//Start Pop
	Resources.Population = Resources.Prev_Population = 10;
	Resources.PopulationCap = 15;

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
	CapUpdates();
	PopulationUpdate();
	ReadOut();
}

void ResourceManager::ReadOut()
{
	std::cout << "Population: " << Resources.Population << "/" << Resources.PopulationCap << " Req: " << Resources.PopReq << std::endl;
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

void ResourceManager::CapUpdates()
{
	Resources.HorseCap = 0;
	Resources.PopulationCap = 15;
	Resources.PopReq = 0;
	Resources.GuildsCount = 0;
	for (int n = 0; n < BManager->BuildingNum; n++)
	{
		if (BManager->BuildingsList[n]->getResources() != nullptr && BManager->BuildingsList[n]->getType() < 900)
		{
			if(BManager->BuildingsList[n]->getType() == Stables) Resources.HorseCap += 5;
			else if (BManager->BuildingsList[n]->getType() == House) Resources.PopulationCap += 10;
			else if (BManager->BuildingsList[n]->getType() == MerchantGuild) Resources.GuildsCount += 1;
			Resources.PopReq += BManager->BuildingsList[n]->getPopReq();
		}
	}
}

void ResourceManager::PopulationUpdate()
{
	if (Resources.Food >= Resources.Population)
	{
		Resources.Food -= Resources.Population;
		Resources.FoodPenalty = 0;
	}
	else
	{
		Resources.FoodPenalty = 1 - ((double)Resources.Food / (double)Resources.Population);
		Resources.Food = 0;
	}
	//Human//
	double PopGrowthMod = 1;
	if (Resources.Population <= Resources.PopulationCap*0.75)
	{
		PopGrowthMod += 0.025;
	}
	if (Resources.Population <= Resources.PopulationCap*0.5)
	{
		PopGrowthMod += 0.025;
	}
	if (Resources.Population <= Resources.PopulationCap*0.25)
	{
		PopGrowthMod += 0.05;
	}
	if (Resources.Population > Resources.PopulationCap)
	{
		PopGrowthMod -= 0.08;
	}
	if (Resources.Population > 1.25*Resources.PopulationCap)
	{
		PopGrowthMod -= 0.12;
	}
	if (Resources.Population > 1.5*Resources.PopulationCap)
	{
		PopGrowthMod -= 0.16;
	}
	if (Resources.Food >= Resources.Population)
	{
		PopGrowthMod += 0.005;
	}
	else if (Resources.Food >= 2*Resources.Population)
	{
		PopGrowthMod += 0.015;
	}
	else if (Resources.Food >= 4 * Resources.Population)
	{
		PopGrowthMod += 0.045;
	}
	int HealthAvg;
	int HappinessAvg;
	int tempsum1 = 0;
	int tempweight1 = 0;
	int tempsum2 = 0;
	int tempweight2 = 0;
	for (int n = 0; n < BManager->BuildingNum && BManager->BuildingsList[n]->getDataDraw().Built == true; n++)
	{
		if (BManager->BuildingsList[n]->getType() < 900)
		{
			tempweight1 += BManager->BuildingsList[n]->getPopReq();
			tempweight2 += BManager->BuildingsList[n]->getPopReq();
			tempsum1 += BManager->BuildingsList[n]->getPopReq() * BManager->BuildingsList[n]->getDataGame().Health;
			tempsum2 += BManager->BuildingsList[n]->getPopReq() * BManager->BuildingsList[n]->getDataGame().Happiness;
		}
	}
	if (tempweight1 > 0) 
	{
		HealthAvg = tempsum1 / tempweight1;
		HappinessAvg = tempsum2 / tempweight2;
	}
	if (HealthAvg >= 75)
	{
		PopGrowthMod += 0.04;
	}
	else if (HealthAvg >= 50)
	{
		PopGrowthMod += 0.01;
	}
	else if (HealthAvg >= 25)
	{
		PopGrowthMod -= 0.01;
	}
	else
	{
		PopGrowthMod -= 0.04;
	}
	if (HappinessAvg >= 75)
	{
		PopGrowthMod += 0.02;
	}
	else if (HappinessAvg >= 50)
	{
		PopGrowthMod += 0.005;
	}
	else if (HappinessAvg >= 25)
	{
		PopGrowthMod -= 0.005;
	}
	else
	{
		PopGrowthMod -= 0.02;
	}
	if (PopGrowthMod > 1)
	{
		Resources.Population = (int)(Resources.Population * PopGrowthMod + 1);
	}
	else if (PopGrowthMod < 1)
	{
		Resources.Population = (int)(Resources.Population * PopGrowthMod - 1);
	}
	//Horse//
	Resources.HorseCap += (int)Resources.HorseOverflow;
	Resources.HorseOverflow -= (int)Resources.HorseOverflow;
	if (Resources.Horses > Resources.HorseCap && Resources.GuildsCount > 0)
	{
		Resources.Ducats += (int)fmin(Resources.GuildsCount * 25, (Resources.Horses - Resources.HorseCap) * 5);
		Resources.Horses = Resources.HorseCap;
	}

	if (Resources.Population < Resources.PopReq) Resources.PopMod = (double)Resources.Population / (double)Resources.PopReq;
	else Resources.PopMod = 1;
}

ResourceManager & ResourceManager::operator=(const ResourceManager & input)
{
	if (this == &input) return *this;

	BManager = input.BManager;

	return *this;
}
