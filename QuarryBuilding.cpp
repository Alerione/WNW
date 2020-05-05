#include "QuarryBuilding.h"

QuarryBuilding::QuarryBuilding()
	: Building()
{
}

QuarryBuilding::QuarryBuilding(const QuarryBuilding & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
}

QuarryBuilding::QuarryBuilding(TileMap * input)
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


QuarryBuilding::~QuarryBuilding()
{
	if (DrawData.Built == 1) RemovalPass();
}

QuarryBuilding& QuarryBuilding::operator=(const QuarryBuilding & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;

	return *this;
}

bool QuarryBuilding::CheckResources()
{
	if (Resources->Ducats < 50 || Resources->Planks < 50) return false;
	return true;
}

void QuarryBuilding::ResourceUpdateTick()
{
	if (DrawData.Built == 1) {
		UpdateBuildingGameData();
		Resources->Marble += 20 * GameData.ResourceMod;
	}
}

void QuarryBuilding::BuildCost()
{
	Resources->Ducats -= 50;
	Resources->Prev_Ducats -= 50;
	Resources->Planks -= 50;
	Resources->Prev_Planks -= 50;
}

void QuarryBuilding::RemovalPass()
{
	Resources->Ducats += 25;
	Resources->Prev_Ducats += 25;
	Resources->Planks += 25;
	Resources->Prev_Planks += 25;
}

void QuarryBuilding::SetupBuildingDatabyType()
{
	Type = Quarry;
	DrawData.BuildingSizeX = 4;
	DrawData.BuildingSizeY = 4;
	DrawData.SpriteOffsetX = -3;
	DrawData.SpriteOffsetY = 80;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getQuarryTexture());
}

void QuarryBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
}
