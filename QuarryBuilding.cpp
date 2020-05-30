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
		Resources->Marble += (unsigned int)(5 * FarmArea() * Resources->PopMod);
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
	GameData.PopReq = 15;
	DrawData.BuildingSizeX = 4;
	DrawData.BuildingSizeY = 4;
	DrawData.SpriteOffsetX = -3;
	DrawData.SpriteOffsetY = 80;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getQuarryTexture());
}

void QuarryBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
	int Range = 4;

	if (DrawData.Built == false)
	{
		int x, y, xadjx, yadj, xadjy;
		for (x = -Range, xadjx = 0, xadjy = 0; x < Range + 4; x++)
		{
			for (y = 0, yadj = 0; y < 2 * Range + 4; y++)
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

int QuarryBuilding::FarmArea()
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
					if (Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->getBuilding()->getType() == Marbles) a++;
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
