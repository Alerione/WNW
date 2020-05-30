#include "LumberBuilding.h"

LumberBuilding::LumberBuilding()
	: Building()
{
}

LumberBuilding::LumberBuilding(const LumberBuilding & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
}

LumberBuilding::LumberBuilding(TileMap * input)
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


LumberBuilding::~LumberBuilding()
{
	if (DrawData.Built == 1) RemovalPass();
}

LumberBuilding& LumberBuilding::operator=(const LumberBuilding & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;

	return *this;
}

bool LumberBuilding::CheckResources()
{
	if (Resources->Ducats < 50) return false;
	return true;
}

void LumberBuilding::ResourceUpdateTick()
{
	if (DrawData.Built == 1) {
		UpdateBuildingGameData();
		Resources->Lumber += (unsigned int)(2 * FarmArea() * Resources->PopMod);
	}
}

void LumberBuilding::BuildCost()
{
	if (DrawData.Built == 1) {
		Resources->Ducats -= 50;
		Resources->Prev_Ducats -= 50;
	}
}

void LumberBuilding::RemovalPass()
{
	Resources->Ducats += 25;
	Resources->Prev_Ducats += 25;
}

void LumberBuilding::SetupBuildingDatabyType()
{
	Type = Lumber;
	GameData.PopReq = 5;
	DrawData.BuildingSizeX = 2;
	DrawData.BuildingSizeY = 2;
	DrawData.SpriteOffsetX = 0;
	DrawData.SpriteOffsetY = 47;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getLumberTexture());
}

void LumberBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
	int Range = 4;

	if (DrawData.Built == false)
	{
		int x, y, xadjx, yadj, xadjy;
		for (x = -Range, xadjx = 0, xadjy = 0; x < Range + 2; x++)
		{
			for (y = 0, yadj = 0; y < 2 * Range + 2; y++)
			{
				yadj = y - x - Range;
				if (Map->checkCurrentTileAdj(x + xadjy - xadjx, yadj))
				{
					BlueOverlaySprite.setPosition((float)Map->getCurrentTileAdj(x + xadjy - xadjx, yadj)->getPositionX(), (float)Map->getCurrentTileAdj(x + xadjy - xadjx, yadj)->getPositionY());
					target.draw(BlueOverlaySprite);
				}
				else
				{
				}
				if ((abs(Map->getCurrentTileY() + y - x - Range)) % 2 == 1) xadjy++;
			}
			xadjy = 0;
			if ((abs(Map->getCurrentTileY() - x - Range)) % 2 == 0) xadjx++;
		}
	}
	else
	{
	}
}

int LumberBuilding::FarmArea()
{
	int a = 0;
	int Range = 4;
	int x, y, xadjx, yadj, xadjy;
	for (x = -Range, xadjx = 0, xadjy = 0; x < Range + 3; x++)
	{
		for (y = 0, yadj = 0; y < 2 * Range + 3; y++)
		{
			yadj = y - x - Range;
			if (Map->checkTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj))
			{
				if (Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->CheckBuilding() != false)
				{
					if (Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->getBuilding()->getType() == Trees) a++;
				}
			}
			else
			{
			}
			if ((abs(TileBase[0][0]->getY() + y - x - Range)) % 2 == 1) xadjy++;
		}
		xadjy = 0;
		if ((abs(TileBase[0][0]->getY() - x - Range)) % 2 == 0) xadjx++;
	}
	return a;
}
