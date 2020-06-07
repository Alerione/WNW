#include "SchoolBuilding.h"


SchoolBuilding::SchoolBuilding()
    : Building()
{
}

SchoolBuilding::SchoolBuilding(const SchoolBuilding & input)
{
    TileBase = input.TileBase;
    Type = input.Type;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;
}

SchoolBuilding::SchoolBuilding(TileMap * input)
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


SchoolBuilding::~SchoolBuilding()
{
    if (DrawData.Built == 1) RemovalPass();
}

SchoolBuilding& SchoolBuilding::operator=(const SchoolBuilding & input)
{
    if (this == &input) return *this;

    Type = input.Type;
    TileBase = input.TileBase;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;

    return *this;
}

bool SchoolBuilding::CheckResources()
{
    if (Resources->Ducats < 200 || Resources->Bricks < 150) return false;
    return true;
}

void SchoolBuilding::ResourceUpdateTick()
{
    if (DrawData.Built == 1) {
        UpdateBuildingGameData();
		if (Resources->Ducats >= 15)
		{
			Resources->Ducats -= 15;
		}
		else UpdateArea(0);
    }
}

void SchoolBuilding::BuildCost()
{
    if (DrawData.Built == 1) {
		Resources->AddDucats(-200, true);
		Resources->AddBricks(-150, true);
    }
}

void SchoolBuilding::RemovalPass()
{
	Resources->AddDucats(100, true);
	Resources->AddBricks(75, true);
}

void SchoolBuilding::SetupBuildingDatabyType()
{
    Type = School;
    GameData.PopReq = 10;
    DrawData.BuildingSizeX = 3;
    DrawData.BuildingSizeY = 3;
    DrawData.SpriteOffsetX = 0;
    DrawData.SpriteOffsetY = 96;
    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getSchoolTexture());
}

void SchoolBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{

}


void SchoolBuilding::UpdateArea(bool a)
{
	int Range = 5;
	int x, y, xadjx, yadj, xadjy;
	for (x = -Range, xadjx = 0, xadjy = 0; x < Range + (int)DrawData.BuildingSizeX; x++)
	{
		for (y = 0, yadj = 0; y < 2 * Range + (int)DrawData.BuildingSizeY; y++)
		{
			yadj = y - x - Range;
			if (Map->checkTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj))
			{
				if(!a)Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addPublicOrder(int(-4));
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
