#include "SawmillBuilding.h"

SawmillBuilding::SawmillBuilding()
	: Building()
{
}

SawmillBuilding::SawmillBuilding(const SawmillBuilding & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
}

SawmillBuilding::SawmillBuilding(TileMap * input)
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


SawmillBuilding::~SawmillBuilding()
{
	if (DrawData.Built == 1) RemovalPass();
}

SawmillBuilding& SawmillBuilding::operator=(const SawmillBuilding & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;

	return *this;
}

void SawmillBuilding::ResourceUpdateTick()
{
	if (DrawData.Built == 1) {
		UpdateBuildingGameData();
		if (Resources->Lumber >= 10 * GameData.ResourceMod)
		{
			Resources->Lumber -= 10 * GameData.ResourceMod;
			Resources->Planks += 10 * GameData.ResourceMod;
		}
	}
}

void SawmillBuilding::BuildCost()
{
	Resources->Ducats -= 100;
	Resources->Prev_Ducats -= 100;
	Resources->Lumber -= 100;
	Resources->Prev_Lumber -= 100;
}

void SawmillBuilding::RemovalPass()
{
	Resources->Ducats += 50;
	Resources->Prev_Ducats += 50;
	Resources->Lumber += 50;
	Resources->Prev_Lumber += 50;
}

void SawmillBuilding::SetupBuildingDatabyType()
{
	Type = Sawmill;
	DrawData.BuildingSizeX = 2;
	DrawData.BuildingSizeY = 2;
	DrawData.SpriteOffsetX = 7;
	DrawData.SpriteOffsetY = 56;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getSawmillTexture());
}

void SawmillBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
}
