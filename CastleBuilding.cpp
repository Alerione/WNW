#include "CastleBuilding.h"


CastleBuilding::CastleBuilding()
    : Building()
{
}

CastleBuilding::CastleBuilding(const CastleBuilding & input)
{
    TileBase = input.TileBase;
    Type = input.Type;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;
}

CastleBuilding::CastleBuilding(TileMap * input)
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


CastleBuilding::~CastleBuilding()
{
    if (DrawData.Built == 1) RemovalPass();
}

CastleBuilding& CastleBuilding::operator=(const CastleBuilding & input)
{
    if (this == &input) return *this;

    Type = input.Type;
    TileBase = input.TileBase;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;

    return *this;
}

bool CastleBuilding::CheckResources()
{
    if (Resources->Ducats < 500 || Resources->Bricks < 500 || Resources->Planks < 300 || Resources->Horses < 10) return false;
    return true;
}

void CastleBuilding::ResourceUpdateTick()
{
    if (DrawData.Built == 1) {
        UpdateBuildingGameData();
		if (Resources->Ducats >= 50 && Resources->Horses >= 10)
		{
			Resources->Ducats -= 50;
			UpdateArea(1);
		}
    }
}

void CastleBuilding::BuildCost()
{
    if (DrawData.Built == 1) {
		Resources->AddDucats(-500, true);
		Resources->AddBricks(-500, true);
		Resources->AddPlanks(-300, true);
    }
}

void CastleBuilding::RemovalPass()
{
	Resources->AddDucats(250, true);
	Resources->AddBricks(250, true);
	Resources->AddPlanks(150, true);
}

void CastleBuilding::SetupBuildingDatabyType()
{
    Type = Castle;
    GameData.PopReq = 60;
    DrawData.BuildingSizeX = 6;
    DrawData.BuildingSizeY = 5;
    DrawData.SpriteOffsetX = 16;
    DrawData.SpriteOffsetY = 186;
    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getCastleTexture());
}

void CastleBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{

}

void CastleBuilding::UpdateArea(bool a)
{
	int Range = 15;
	int x, y, xadjx, yadj, xadjy;
	for (x = -Range, xadjx = 0, xadjy = 0; x < Range + (int)DrawData.BuildingSizeX; x++)
	{
		for (y = 0, yadj = 0; y < 2 * Range + (int)DrawData.BuildingSizeY; y++)
		{
			yadj = y - x - Range;
			if (Map->checkTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj))
			{
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addPublicOrder(int(15 * a));
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addHappiness(int(-5 * a));
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