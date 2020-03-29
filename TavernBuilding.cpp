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
	for (int x = 0; x < DrawData.BuildingSizeX; x++)
	{
		TileBase[x].resize(DrawData.BuildingSizeY);
		for (int y = 0; y < DrawData.BuildingSizeY; y++)
		{
			TileBase[x][y] = nullptr;
		}
	}
	if (CollisionSpriteSet == 0)
	{
		CollisionSpriteSet = 1;
		CollisionSprite = sf::Sprite(Map->getTexMngr().getCollisionTexture());
	}
}


TavernBuilding::~TavernBuilding()
{
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

bool TavernBuilding::operator<(const TavernBuilding & input)
{

	if (input.TileBase[0][0]->getPositionY() < this->TileBase[0][0]->getPositionY()) return true;
	if ((input.TileBase[0][0]->getPositionY() == this->TileBase[0][0]->getPositionY()) && (input.TileBase[0][0]->getPositionX() < this->TileBase[0][0]->getPositionX())) return true;
	return false;
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
