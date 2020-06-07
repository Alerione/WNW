#include "HospitalBuilding.h"


HospitalBuilding::HospitalBuilding()
    : Building()
{
}

HospitalBuilding::HospitalBuilding(const HospitalBuilding & input)
{
    TileBase = input.TileBase;
    Type = input.Type;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;
}

HospitalBuilding::HospitalBuilding(TileMap * input)
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


HospitalBuilding::~HospitalBuilding()
{
    if (DrawData.Built == 1) RemovalPass();
}

HospitalBuilding& HospitalBuilding::operator=(const HospitalBuilding & input)
{
    if (this == &input) return *this;

    Type = input.Type;
    TileBase = input.TileBase;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;

    return *this;
}

bool HospitalBuilding::CheckResources()
{
    if (Resources->Ducats < 500 || Resources->EducationFactor < 0.5 || Resources->Bricks < 250) return false;
    return true;
}

void HospitalBuilding::ResourceUpdateTick()
{
    if (DrawData.Built == 1) {
        UpdateBuildingGameData();
		if (Resources->Ducats > 40 && Resources->EducationFactor >= 0.5)
		{
			Resources->AddDucats(-40, false);
			UpdateArea(1);
		}
    }
}

void HospitalBuilding::BuildCost()
{
    if (DrawData.Built == 1) {
		Resources->AddDucats(-500, true);
		Resources->AddBricks(-250, true);
    }
}

void HospitalBuilding::RemovalPass()
{
	Resources->AddDucats(250, true);
	Resources->AddBricks(125, true);
}

void HospitalBuilding::SetupBuildingDatabyType()
{
    Type = Hospital;
    GameData.PopReq = 40;
    DrawData.BuildingSizeX = 7;
    DrawData.BuildingSizeY = 8;
    DrawData.SpriteOffsetX = -12;
    DrawData.SpriteOffsetY = 262;
    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getHospitalTexture());
}

void HospitalBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{

}


void HospitalBuilding::UpdateArea(bool a)
{
	int Range = 10;
	int x, y, xadjx, yadj, xadjy;
	for (x = -Range, xadjx = 0, xadjy = 0; x < Range + (int)DrawData.BuildingSizeX; x++)
	{
		for (y = 0, yadj = 0; y < 2 * Range + (int)DrawData.BuildingSizeY; y++)
		{
			yadj = y - x - Range;
			if (Map->checkTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj))
			{
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addHealth(int(10 * a));
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