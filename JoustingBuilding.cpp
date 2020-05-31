#include "JoustingBuilding.h"

JoustingBuilding::JoustingBuilding()
	: Building()
{
}

JoustingBuilding::JoustingBuilding(const JoustingBuilding & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
}

JoustingBuilding::JoustingBuilding(TileMap * input)
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


JoustingBuilding::~JoustingBuilding()
{
	if (DrawData.Built == 1) RemovalPass();
}

JoustingBuilding& JoustingBuilding::operator=(const JoustingBuilding & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;

	return *this;
}

bool JoustingBuilding::CheckResources()
{
	if (Resources->Ducats < 400 || Resources->Bricks < 150 || Resources->MarbleBlocks < 150) return false;
	return true;
}

void JoustingBuilding::ResourceUpdateTick()
{
	if (DrawData.Built == 1) {
		UpdateBuildingGameData();
		if (Resources->Ducats >= 35)
		{
			Resources->Ducats -= 35;
			UpdateArea();
		}
	}
}

void JoustingBuilding::BuildCost()
{
	Resources->Ducats -= 400;
	Resources->Prev_Ducats -= 400;
	Resources->Bricks -= 150;
	Resources->Prev_Bricks -= 150;
	Resources->MarbleBlocks -= 150;
	Resources->Prev_MarbleBlocks -= 150;
}

void JoustingBuilding::RemovalPass()
{
	Resources->Prev_Ducats += 200;
	Resources->Ducats += 200;
	Resources->Prev_Bricks += 75;
	Resources->Bricks += 75;
	Resources->MarbleBlocks += 75;
	Resources->Prev_MarbleBlocks += 75;
}

void JoustingBuilding::SetupBuildingDatabyType()
{
	Type = Jousting;
	GameData.PopReq = 20;
	DrawData.BuildingSizeX = 4;
	DrawData.BuildingSizeY = 5;
	DrawData.SpriteOffsetX = 0;
	DrawData.SpriteOffsetY = 108;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getJoustingTexture());
}

void JoustingBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
}

void JoustingBuilding::UpdateArea()
{
	int Range = 7;
	int x, y, xadjx, yadj, xadjy;
	for (x = -Range, xadjx = 0, xadjy = 0; x < Range + 4; x++)
	{
		for (y = 0, yadj = 0; y < 2 * Range + 5; y++)
		{
			yadj = y - x - Range;
			if (Map->checkTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj))
			{
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addHappiness(10);
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addPublicOrder(-2);
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addHealth(-1);
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
