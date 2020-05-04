#include "Building.h"
#include <algorithm>

bool Building::BusyBuilding = 0;
sf::Sprite Building::CollisionSprite = sf::Sprite();
sf::Sprite Building::BlueOverlaySprite = sf::Sprite();
bool Building::StaticSpriteSet = 0;

Building::Building()
	: TileBase{}
	, Type(Unspecified)
	, DrawData{}
	, GameData{}
	, Map(nullptr)
{

}

Building::Building(const Building & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
}


Building::~Building()
{
	if (DrawData.Built == 0) BusyBuilding = 0;
}

Building & Building::operator=(const Building & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;

	return *this;
}


ResourceList * Building::getResources()
{
	return Resources;
}

bool Building::CheckCollision()
{
	for (unsigned int x = 0; x < DrawData.BuildingSizeX; x++)
	{
		for (unsigned int y = 0; y < DrawData.BuildingSizeY; y++)
		{
			if (TileBase[x][y] == nullptr || TileBase[x][y]->CheckBuilding() == true)
			{
				return true;
			}
		}
	}
	return false;
}

void Building::DrawCollision(sf::RenderTarget & target)
{
	for (unsigned int x = 0; x < DrawData.BuildingSizeX; x++)
	{
		for (unsigned int y = 0; y < DrawData.BuildingSizeY; y++)
		{
			if (TileBase[x][y] != nullptr && TileBase[x][y]->CheckBuilding() == true)
			{
				CollisionSprite.setPosition((float)TileBase[x][y]->getPositionX(), (float)TileBase[x][y]->getPositionY());
				target.draw(CollisionSprite);
			}
		}
	}
}

void Building::Build(ResourceList* Resources)
{
	if (CheckCollision() == true) return;
	this->Resources = Resources;
	if (CheckResources() == false)
	{
		this->Resources = nullptr; return;
	}

	for (unsigned int x = 0; x < DrawData.BuildingSizeX; x++)
	{
		for (unsigned int y = 0; y < DrawData.BuildingSizeY; y++)
		{
			TileBase[x][y]->SetBulding(this);
		}
	}
	DrawData.Built = true;
	BusyBuilding = false;
	BuildCost();
	DrawData.Sprite.setPosition((float)TileBase[0][0]->getPositionX()-DrawData.SpriteOffsetX, (float)TileBase[0][0]->getPositionY()-DrawData.SpriteOffsetY);
}

void Building::draw(sf::RenderWindow& target)
{
	if (DrawData.Built == false)
	{
		UpdatePositionbyMouse(target);
		DrawData.Sprite.setPosition((float)TileBase[0][0]->getPositionX()-DrawData.SpriteOffsetX, (float)TileBase[0][0] ->getPositionY() - DrawData.SpriteOffsetY);
		target.draw(DrawData.Sprite);
		DrawCollision(target);
	}
	else
	{
		target.draw(DrawData.Sprite);
	}
	DrawBuildingSpecific(target);
}

void Building::UpdatePositionbyMouse(sf::RenderWindow & target)
{
	int x, y, xadjx, yadj, xadjy;
	for (x = 0, xadjx = 0, xadjy=0; x < (int)DrawData.BuildingSizeX;x++)
	{
		for (y = 0, yadj = 0; y < (int)DrawData.BuildingSizeY; y++)
		{
			yadj = y - x;
			if (Map->checkCurrentTileAdj(x+xadjy-xadjx, yadj))
			{
				TileBase[x][y] = Map->getCurrentTileAdj(x+xadjy - xadjx, yadj);
			}
			else
			{
				TileBase[x][y] = nullptr;
			}
			if ((abs(Map->getCurrentTileY() + y - x)) % 2 == 1) xadjy++;
		}
		xadjy = 0;
		if((abs(Map->getCurrentTileY() - x ))% 2 == 0) xadjx++;
	}
}

bool Building::CheckBusy()
{
	return BusyBuilding;
}

bool Building::CheckResources()
{
	//Building Costs Switch//
	switch (Type) {
		case 1:
			if (Resources->Ducats < 250 || Resources->Bricks < 100) return false;
			break;
		case 2:
			if (Resources->Ducats < 100 || Resources->Bricks < 50) return false;
			break;
		case 3:
			if (Resources->Ducats < 150) return false;
			break;
		case 4:
			if (Resources->Ducats < 100 || Resources->Lumber < 100) return false;
			break;
		case 5:
			if (Resources->Ducats < 50 || Resources->Planks < 50) return false;
			break;
		default:
			return false;
	}
	return true;
}

void Building::UpdateBuildingGameData()
{
	int mod = 5;
	bool water = false;
	int TileCount = DrawData.BuildingSizeX*DrawData.BuildingSizeY;
	double HappinessSum = 0;
	double PublicOrderSum = 0;
	double HealthSum = 0;

	for (unsigned int x = 0; x < DrawData.BuildingSizeX; x++)
	{
		for (unsigned int y = 0; y < DrawData.BuildingSizeY; y++)
		{
			if (TileBase[x][y]->getWaterAccess() == true) water = true;
			HappinessSum += TileBase[x][y]->getHappiness();
			PublicOrderSum += TileBase[x][y]->getPublicOrder();
			HealthSum += TileBase[x][y]->getHealth();

		}
	}
	GameData.WaterAccess = water;
	HappinessSum /= TileCount;
	PublicOrderSum /= TileCount;
	HealthSum /= TileCount;
	double tPublicOrderSum = PublicOrderSum;
	PublicOrderSum -= mod - (mod * (HappinessSum / 100));
	HappinessSum -= mod - (mod * (tPublicOrderSum / 100));
	HappinessSum -= 0.5*mod - (0.5 * mod * (HealthSum / 100));
	if (Resources->Population > 0.75*Resources->PopulationCap && Resources->PopulationCap!=0)
	{
		HappinessSum -= mod * ((((Resources->PopulationCap - Resources->Population) / Resources->PopulationCap)) - 0.75) * 2;
		PublicOrderSum -= mod * ((((Resources->PopulationCap - Resources->Population) / Resources->PopulationCap)) - 0.75) * 2;
		HealthSum -= mod * ((((Resources->PopulationCap - Resources->Population) / Resources->PopulationCap)) - 0.75) * 2;
	}
	if (water == false)
	{
		HealthSum -= mod;
		HappinessSum -= mod;
	}
	GameData.Happiness = (unsigned int)fmin(100, fmax(0, HappinessSum));
	GameData.PublicOrder = (unsigned int)fmin(100, fmax(0, PublicOrderSum));
	GameData.Health = (unsigned int)fmin(100, fmax(0, HealthSum));

	for (unsigned int x = 0; x < DrawData.BuildingSizeX; x++)
	{
		for (unsigned int y = 0; y < DrawData.BuildingSizeY; y++)
		{
			TileBase[x][y]->setHappiness(GameData.Happiness);
			TileBase[x][y]->setHealth(GameData.Health);
			TileBase[x][y]->setPublicOrder(GameData.PublicOrder);
		}
	}
	double a = 0.4 * (1 - ((double)GameData.Happiness / 100));
	double b = 0.4 * (1 - ((double)GameData.PublicOrder / 100));
	double c = 0.2 * (1 - ((double)GameData.Health / 100));
	GameData.ResourceMod = 1 * (1-a) * (1-b) * (1-c);
}
