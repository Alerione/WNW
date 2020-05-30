#include "HouseBuilding.h"

HouseBuilding::HouseBuilding()
	: Building()
{
}

HouseBuilding::HouseBuilding(const HouseBuilding & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
}

HouseBuilding::HouseBuilding(TileMap * input)
	: Building()
{
	BusyBuilding = true;
	Map = input;
	SetupBuildingDatabyType();
	TileBase.resize(DrawData.BuildingSizeX);
	for (unsigned int x = 0; x < DrawData.BuildingSizeX; x++)
	{
		TileBase[x].resize(DrawData.BuildingSizeY);
		for (unsigned int y = 0; y < DrawData.BuildingSizeY; y++)
		{
			TileBase[x][y] = nullptr;
		}
	}
	if (StaticSpriteSet == 0)
	{
		StaticSpriteSet = 1;
		CollisionSprite = sf::Sprite(Map->getTexMngr().getCollisionTexture());
		BlueOverlaySprite = sf::Sprite(Map->getTexMngr().getBlueOverlayTexture());
	}
}


HouseBuilding::~HouseBuilding()
{
	if (DrawData.Built == 1) RemovalPass();
}

HouseBuilding& HouseBuilding::operator=(const HouseBuilding & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;

	return *this;
}

bool HouseBuilding::CheckResources()
{
	if (Resources->Ducats < 50) return false;
	return true;
}

void HouseBuilding::ResourceUpdateTick()
{
	if (DrawData.Built == 1) {
		UpdateBuildingGameData();
	}
}

void HouseBuilding::BuildCost()
{
	Resources->Ducats -= 50;
	Resources->Prev_Ducats -= 50;
}

void HouseBuilding::RemovalPass()
{
	Resources->Ducats += 25;
	Resources->Prev_Ducats += 25;
}

void HouseBuilding::SetupBuildingDatabyType()
{
	Type = House;
	GameData.PopReq = 2;
	DrawData.BuildingSizeX = 2;
	DrawData.BuildingSizeY = 2;
	DrawData.SpriteOffsetX = 0;
	DrawData.SpriteOffsetY = 80;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getHouseTexture(rand()%2));
}

void HouseBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
}
