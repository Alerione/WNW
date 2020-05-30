#include "HorseBreederBuilding.h"

HorseBreederBuilding::HorseBreederBuilding()
	: Building()
{
}

HorseBreederBuilding::HorseBreederBuilding(const HorseBreederBuilding & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
}

HorseBreederBuilding::HorseBreederBuilding(TileMap * input)
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


HorseBreederBuilding::~HorseBreederBuilding()
{
	if (DrawData.Built == 1) RemovalPass();
}

HorseBreederBuilding& HorseBreederBuilding::operator=(const HorseBreederBuilding & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;

	return *this;
}

bool HorseBreederBuilding::CheckResources()
{
	if (Resources->Ducats < 150 || Resources->Planks < 100) return false;
	return true;
}

void HorseBreederBuilding::ResourceUpdateTick()
{
	if (DrawData.Built == 1) {
		UpdateBuildingGameData();
		Resources->HorseOverflow += ((double)FarmArea() * Resources->PopMod);
	}
}

void HorseBreederBuilding::BuildCost()
{
	if (DrawData.Built == 1) {
		Resources->Ducats -= 150;
		Resources->Prev_Ducats -= 150;
		Resources->Planks -= 100;
		Resources->Prev_Planks -= 100;
	}
}

void HorseBreederBuilding::RemovalPass()
{
	Resources->Ducats += 75;
	Resources->Prev_Ducats += 75;
	Resources->Planks += 50;
	Resources->Prev_Planks += 50;
}

void HorseBreederBuilding::SetupBuildingDatabyType()
{
	Type = HorseBreeder;
	GameData.PopReq = 5;
	DrawData.BuildingSizeX = 3;
	DrawData.BuildingSizeY = 3;
	DrawData.SpriteOffsetX = 0;
	DrawData.SpriteOffsetY = 47;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getHorseBreederTexture());
}

void HorseBreederBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
	int Range = 4;

	if (DrawData.Built == false)
	{
		int x, y, xadjx, yadj, xadjy;
		for (x = -Range, xadjx = 0, xadjy = 0; x < Range + 3; x++)
		{
			for (y = 0, yadj = 0; y < 2 * Range + 3; y++)
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

int HorseBreederBuilding::FarmArea()
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
					if (Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->getBuilding()->getType() == Horsess) a++;
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
