#include "WellBuilding.h"

WellBuilding::WellBuilding()
	: Building()
{
}

WellBuilding::WellBuilding(const WellBuilding & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
}

WellBuilding::WellBuilding(TileMap * input)
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


WellBuilding::~WellBuilding()
{
	if (DrawData.Built == 1) RemovalPass();
}

WellBuilding& WellBuilding::operator=(const WellBuilding & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;

	return *this;
}

void WellBuilding::ResourceUpdateTick()
{
	UpdateBuildingGameData();
	Resources->Ducats -= 1;
	UpdateArea(true);
}

void WellBuilding::BuildCost()
{
	Resources->Ducats -= 100;
	Resources->Bricks -= 50;
}

void WellBuilding::RemovalPass()
{
	Resources->Ducats += 50;
	Resources->Bricks += 25;
	UpdateArea(false);
}

void WellBuilding::SetupBuildingDatabyType()
{
	Type = Well;
	DrawData.BuildingSizeX = 1;
	DrawData.BuildingSizeY = 1;
	DrawData.SpriteOffsetX = 0;
	DrawData.SpriteOffsetY = 27;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getWellTexture());
}

void WellBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
	int Range = 2;

	if (DrawData.Built == false)
	{
		int x, y, xadjx, yadj, xadjy;
		for (x = -Range, xadjx = 0, xadjy = 0; x < Range+1; x++)
		{
			for (y = 0, yadj = 0; y < 2*Range+1; y++)
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

void WellBuilding::UpdateArea(bool a)
{
	int Range = 2;
	int x, y, xadjx, yadj, xadjy;
	for (x = -Range, xadjx = 0, xadjy = 0; x < Range + 1; x++)
	{
		for (y = 0, yadj = 0; y < 2 * Range + 1; y++)
		{
			yadj = y - x - Range;
			if (Map->checkCurrentTileAdj(x + xadjy - xadjx, yadj))
			{
				Map->getCurrentTileAdj(x + xadjy - xadjx, yadj)->setWaterAccess(a);
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
