#include "BarracksBuilding.h"

BarracksBuilding::BarracksBuilding()
	: Building()
{
}

BarracksBuilding::BarracksBuilding(const BarracksBuilding & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
}

BarracksBuilding::BarracksBuilding(TileMap * input)
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


BarracksBuilding::~BarracksBuilding()
{
	if (DrawData.Built == 1) RemovalPass();
}

BarracksBuilding& BarracksBuilding::operator=(const BarracksBuilding & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;

	return *this;
}

bool BarracksBuilding::CheckResources()
{
	if (Resources->Ducats < 350 || Resources->Planks < 100 || Resources->Bricks < 200) return false;
	return true;
}

void BarracksBuilding::ResourceUpdateTick()
{
	if (DrawData.Built == 1) {
		UpdateBuildingGameData();
		if (Resources->Ducats >= 35)
		{
			Resources->Ducats -= 35;
			UpdateArea(1);
		}
	}
}

void BarracksBuilding::BuildCost()
{
	Resources->Ducats -= 350;
	Resources->Prev_Ducats -= 350;
	Resources->Bricks -= 200;
	Resources->Prev_Bricks -= 200;
	Resources->Planks -= 100;
	Resources->Prev_Planks -= 100;
}

void BarracksBuilding::RemovalPass()
{
	Resources->Ducats += 175;
	Resources->Prev_Ducats += 175;
	Resources->Bricks += 100;
	Resources->Prev_Bricks += 100;
	Resources->Planks += 50;
	Resources->Prev_Planks += 50;
}

void BarracksBuilding::SetupBuildingDatabyType()
{
	Type = Barracks;
	GameData.PopReq = 25;
	DrawData.BuildingSizeX = 2;
	DrawData.BuildingSizeY = 2;
	DrawData.SpriteOffsetX = 0;
	DrawData.SpriteOffsetY = 104;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getBarracksTexture());
}

void BarracksBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
}

void BarracksBuilding::UpdateArea(bool a)
{
	int Range = 5;
	int x, y, xadjx, yadj, xadjy;
	for (x = -Range, xadjx = 0, xadjy = 0; x < Range + (int)DrawData.BuildingSizeX; x++)
	{
		for (y = 0, yadj = 0; y < 2 * Range + (int)DrawData.BuildingSizeY; y++)
		{
			yadj = y - x - Range;
			if (Map->checkTileAdj(TileBase[0][0]->getX(),TileBase[0][0]->getY(),x + xadjy - xadjx, yadj))
			{
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(),x + xadjy - xadjx, yadj)->addPublicOrder(int(10*a));
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addHappiness(int(-3 * a));
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

