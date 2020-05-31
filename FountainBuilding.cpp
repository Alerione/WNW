#include "FountainBuilding.h"

FountainBuilding::FountainBuilding()
	: Building()
{
}

FountainBuilding::FountainBuilding(const FountainBuilding & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
}

FountainBuilding::FountainBuilding(TileMap * input)
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


FountainBuilding::~FountainBuilding()
{
	if (DrawData.Built == 1) RemovalPass();
}

FountainBuilding& FountainBuilding::operator=(const FountainBuilding & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;

	return *this;
}

bool FountainBuilding::CheckResources()
{
	if (Resources->Ducats < 200 || Resources->MarbleBlocks < 100) return false;
	return true;
}

void FountainBuilding::ResourceUpdateTick()
{
	UpdateBuildingGameData();
	if (Resources->Ducats >= 5)
	{
		Resources->Ducats -= 5;
		UpdateArea(true);
	}
	else
	{
		UpdateArea(false);
		//Lower local health?
	}
}

void FountainBuilding::BuildCost()
{
	if (DrawData.Built == 1) {
		Resources->Ducats -= 200;
		Resources->Prev_Ducats -= 200;
		Resources->MarbleBlocks -= 100;
		Resources->Prev_MarbleBlocks -= 100;
	}
}

void FountainBuilding::RemovalPass()
{
	Resources->Ducats += 100;
	Resources->Prev_Ducats += 100;
	Resources->MarbleBlocks += 50;
	Resources->Prev_MarbleBlocks += 50;
	UpdateArea(false);
}

void FountainBuilding::SetupBuildingDatabyType()
{
	Type = Fountain;
	GameData.PopReq = 2;
	DrawData.BuildingSizeX = 2;
	DrawData.BuildingSizeY = 2;
	DrawData.SpriteOffsetX = 0;
	DrawData.SpriteOffsetY = 90;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getFountainTexture());
}

void FountainBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
	int Range = 6;

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

void FountainBuilding::UpdateArea(bool a)
{
	int Range = 6;
	int x, y, xadjx, yadj, xadjy;
	for (x = -Range, xadjx = 0, xadjy = 0; x < Range + 2; x++)
	{
		for (y = 0, yadj = 0; y < 2 * Range + 2; y++)
		{
			yadj = y - x - Range;
			if (Map->checkTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj))
			{
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->setWaterAccess(a);
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addHealth(int(5 * a));
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
