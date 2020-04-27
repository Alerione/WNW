#include "TavernBuilding.h"

TavernBuilding::TavernBuilding()
	: Building()
{
}

TavernBuilding::TavernBuilding(const TavernBuilding & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
}

TavernBuilding::TavernBuilding(TileMap * input)
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


TavernBuilding::~TavernBuilding()
{
	if (DrawData.Built == 1) RemovalPass();
}

TavernBuilding& TavernBuilding::operator=(const TavernBuilding & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;

	return *this;
}

void TavernBuilding::ResourceUpdateTick()
{
	UpdateBuildingGameData();
	Resources->Ducats += (unsigned int)(25*GameData.ResourceMod);
}

void TavernBuilding::BuildCost()
{
	Resources->Ducats -= 250;
	Resources->Bricks -= 100;
}

void TavernBuilding::RemovalPass()
{
	Resources->Ducats += 125;
	Resources->Bricks += 50;
}

void TavernBuilding::SetupBuildingDatabyType()
{
	Type = Tavern;
	DrawData.BuildingSizeX = 2;
	DrawData.BuildingSizeY = 2;
	DrawData.SpriteOffsetX = 13;
	DrawData.SpriteOffsetY = 100;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getTavernTexture());
}

void TavernBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
}
