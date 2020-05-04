#include "StablesBuilding.h"

StablesBuilding::StablesBuilding()
	: Building()
{
}

StablesBuilding::StablesBuilding(const StablesBuilding & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
}

StablesBuilding::StablesBuilding(TileMap * input)
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


StablesBuilding::~StablesBuilding()
{
	if (DrawData.Built == 1) RemovalPass();
}

StablesBuilding& StablesBuilding::operator=(const StablesBuilding & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;

	return *this;
}

void StablesBuilding::ResourceUpdateTick()
{
	if (DrawData.Built == 1) {
		UpdateBuildingGameData();
		Resources->Ducats += (unsigned int)(5 * GameData.ResourceMod);
	}
}

void StablesBuilding::BuildCost()
{
	Resources->HorseCap += 10;
	Resources->Ducats -= 150;
	Resources->Prev_Ducats -= 150;
}

void StablesBuilding::RemovalPass()
{
	Resources->HorseCap -= 10;
	Resources->Ducats += 75;
	Resources->Prev_Ducats += 75;
}

void StablesBuilding::SetupBuildingDatabyType()
{
	Type = Stables;
	DrawData.BuildingSizeX = 3;
	DrawData.BuildingSizeY = 3;
	DrawData.SpriteOffsetX = 20;
	DrawData.SpriteOffsetY = 105;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getStablesTexture());
}

void StablesBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
}
