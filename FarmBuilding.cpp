#include "FarmBuilding.h"

FarmBuilding::FarmBuilding()
	: Building()
	, FarmGrowth(0)
	, FarmSprite{}
{
}

FarmBuilding::FarmBuilding(const FarmBuilding & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
	FarmGrowth = 0;
	for (int i = 0; i < 4; i++)
	{
		FarmSprite[i] = input.FarmSprite[i];
	}
}

FarmBuilding::FarmBuilding(TileMap * input)
	: Building()
	, FarmGrowth(0)
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


FarmBuilding::~FarmBuilding()
{
	if (DrawData.Built == 1) RemovalPass();
}

FarmBuilding& FarmBuilding::operator=(const FarmBuilding & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
	FarmGrowth = 0;
	for (int i = 0; i < 4; i++)
	{
		FarmSprite[i] = input.FarmSprite[i];
	}

	return *this;
}

bool FarmBuilding::CheckResources()
{
	if (Resources->Ducats < 100 || Resources->Bricks < 50) return false;
	return true;
}

void FarmBuilding::ResourceUpdateTick()
{
	FarmGrowth++;
	if (FarmGrowth == 4)
	{
		Resources->Food += 80;
		FarmGrowth = 0;
	}
}

void FarmBuilding::BuildCost()
{
	if (DrawData.Built == 1) {
		Resources->Ducats -= 100;
		Resources->Prev_Ducats -= 100;
		Resources->Lumber -= 50;
		Resources->Prev_Lumber -= 50;
	}
	//UpdateArea(true);
}

void FarmBuilding::RemovalPass()
{
	Resources->Ducats += 50;
	Resources->Prev_Ducats += 50;
	Resources->Lumber += 25;
	Resources->Prev_Lumber += 25;
	//UpdateArea(false);
}

void FarmBuilding::SetupBuildingDatabyType()
{
	Type = Farm;
	DrawData.BuildingSizeX = 3;
	DrawData.BuildingSizeY = 3;
	DrawData.SpriteOffsetX = 0;
	DrawData.SpriteOffsetY = 27;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getFarmTexture());
	for (int i = 0; i < 4; i++)
	{
		FarmSprite[i] = sf::Sprite(Map->getTexMngr().getFarmlandTexture(i));
	}
}

void FarmBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
	if (!(DrawData.Built)) 
	{
		int Range = 2;
		int x, y, xadjx, yadj, xadjy;
		for (x = 0, xadjx = 0, xadjy = 0; x < Range + 1; x++)
		{
			for (y = 0, yadj = 0; y < Range + 1; y++)
			{
				yadj = y - x - Range;
				if (x == 0 & y == 0)
				{

				}
				else if (Map->checkCurrentTileAdj(x + xadjy - xadjx, yadj))
				{
					BlueOverlaySprite.setPosition((float)Map->getCurrentTileAdj(x + xadjy - xadjx, yadj)->getPositionX(), (float)Map->getCurrentTileAdj(x + xadjy - xadjx, yadj)->getPositionY() + 25);
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
		FarmSprite[FarmGrowth].setPosition(TileBase[2][0]->getPositionX(), TileBase[2][0]->getPositionY() - 5);
		target.draw(FarmSprite[FarmGrowth]);
		FarmSprite[FarmGrowth].setPosition(TileBase[1][0]->getPositionX(), TileBase[1][0]->getPositionY() - 5);
		target.draw(FarmSprite[FarmGrowth]);
		FarmSprite[FarmGrowth].setPosition(TileBase[2][1]->getPositionX(), TileBase[2][1]->getPositionY() - 5);
		target.draw(FarmSprite[FarmGrowth]);
		FarmSprite[FarmGrowth].setPosition(TileBase[1][1]->getPositionX(), TileBase[1][1]->getPositionY() - 5);
		target.draw(FarmSprite[FarmGrowth]);
		FarmSprite[FarmGrowth].setPosition(TileBase[2][2]->getPositionX(), TileBase[2][2]->getPositionY() - 5);
		target.draw(FarmSprite[FarmGrowth]);
		FarmSprite[FarmGrowth].setPosition(TileBase[0][1]->getPositionX(), TileBase[0][1]->getPositionY() - 5);
		target.draw(FarmSprite[FarmGrowth]);
		FarmSprite[FarmGrowth].setPosition(TileBase[1][2]->getPositionX(), TileBase[1][2]->getPositionY() - 5);
		target.draw(FarmSprite[FarmGrowth]);
		FarmSprite[FarmGrowth].setPosition(TileBase[0][2]->getPositionX(), TileBase[0][2]->getPositionY() - 5);
		target.draw(FarmSprite[FarmGrowth]);
	}
	if (!(DrawData.Built)&&CheckCollision())
	{
		for (unsigned int x = 0; x < DrawData.BuildingSizeX; x++)
		{
			for (unsigned int y = 0; y < DrawData.BuildingSizeY; y++)
			{
				if (TileBase[x][y] != nullptr)
				{
					CollisionSprite.setPosition((float)TileBase[x][y]->getPositionX(), (float)TileBase[x][y]->getPositionY());
					target.draw(CollisionSprite);
				}
			}
		}
	}
}