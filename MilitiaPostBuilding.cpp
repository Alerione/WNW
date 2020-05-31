#include "MilitiaPostBuilding.h"


MilitiaPostBuilding::MilitiaPostBuilding()
	: Building()
{
}

MilitiaPostBuilding::MilitiaPostBuilding(const MilitiaPostBuilding & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
}

MilitiaPostBuilding::MilitiaPostBuilding(TileMap * input)
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


MilitiaPostBuilding::~MilitiaPostBuilding()
{
	if (DrawData.Built == 1) RemovalPass();
}

MilitiaPostBuilding& MilitiaPostBuilding::operator=(const MilitiaPostBuilding & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;

	return *this;
}

bool MilitiaPostBuilding::CheckResources()
{
	if (Resources->Ducats < 150 || Resources->Planks < 100 || Resources->Bricks < 50) return false;
	return true;
}

void MilitiaPostBuilding::ResourceUpdateTick()
{
	if (DrawData.Built == 1) {
		UpdateBuildingGameData();
		if (Resources->Ducats >= 5)
		{
			Resources->Ducats -= 5;
			UpdateArea(1);
		}
	}
}

void MilitiaPostBuilding::BuildCost()
{
	Resources->Ducats -= 150;
	Resources->Prev_Ducats -= 150;
	Resources->Bricks -= 50;
	Resources->Prev_Bricks -= 50;
	Resources->Planks -= 100;
	Resources->Prev_Planks -= 100;
}

void MilitiaPostBuilding::RemovalPass()
{
	Resources->Ducats += 75;
	Resources->Prev_Ducats += 75;
	Resources->Bricks += 25;
	Resources->Prev_Bricks += 25;
	Resources->Planks += 50;
	Resources->Prev_Planks += 50;
}

void MilitiaPostBuilding::SetupBuildingDatabyType()
{
	Type = MilitiaPost;
	GameData.PopReq = 4;
	DrawData.BuildingSizeX = 2;
	DrawData.BuildingSizeY = 2;
	DrawData.SpriteOffsetX = 16;
	DrawData.SpriteOffsetY = 124;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getMilitiaPostTexture());
}

void MilitiaPostBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
}

void MilitiaPostBuilding::UpdateArea(bool a)
{
	int Range = 4;
	int x, y, xadjx, yadj, xadjy;
	for (x = -Range, xadjx = 0, xadjy = 0; x < Range + 2; x++)
	{
		for (y = 0, yadj = 0; y < 2 * Range + 2; y++)
		{
			yadj = y - x - Range;
			if (Map->checkTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj))
			{
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addPublicOrder(int(3 * a));
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addHappiness(int(-1 * a));
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

