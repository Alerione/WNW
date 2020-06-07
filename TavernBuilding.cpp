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

bool TavernBuilding::CheckResources()
{
	if (Resources->Ducats < 250 || Resources->Bricks < 100) return false;
	return true;
}

void TavernBuilding::ResourceUpdateTick()
{
	if (DrawData.Built == 1) {
		UpdateBuildingGameData();
		UpdateArea(0);
		if (Resources->Beer > 5)
		{
			Resources->Beer -= 5;
			UpdateArea(1);
		}
	}
}

void TavernBuilding::BuildCost()
{
	Resources->Ducats -= 250;
	Resources->Prev_Ducats -= 250;
	Resources->Bricks -= 100;
	Resources->Prev_Bricks -= 100;
}

void TavernBuilding::RemovalPass()
{
	Resources->Prev_Ducats += 125;
	Resources->Ducats += 125;
	Resources->Prev_Bricks += 50;
	Resources->Bricks += 50;
}

void TavernBuilding::SetupBuildingDatabyType()
{
	Type = Tavern;
	GameData.PopReq = 10;
	DrawData.BuildingSizeX = 2;
	DrawData.BuildingSizeY = 2;
	DrawData.SpriteOffsetX = 13;
	DrawData.SpriteOffsetY = 100;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getTavernTexture());
}

void TavernBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
}

void TavernBuilding::UpdateArea(bool beer)
{
	int Range = 4;
	int x, y, xadjx, yadj, xadjy;
	for (x = -Range, xadjx = 0, xadjy = 0; x < Range + (int)DrawData.BuildingSizeX; x++)
	{
		for (y = 0, yadj = 0; y < 2 * Range + (int)DrawData.BuildingSizeY; y++)
		{
			yadj = y - x - Range;
			if (Map->checkTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj))
			{
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addHappiness(3);
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addPublicOrder(-1);
				if(beer)Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addHealth(-1);
			}
			else
			{
			}
			if ((abs(TileBase[0][0]->getY() + y - x - Range)) % 2 == 1) xadjy++;
		}
		xadjy = 0;
		if ((abs(TileBase[0][0]->getY() - x - Range)) % 2 == 0) xadjx++;
	}

}
