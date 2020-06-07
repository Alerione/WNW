#include "DoctorBuilding.h"


DoctorBuilding::DoctorBuilding()
    : Building()
{
}

DoctorBuilding::DoctorBuilding(const DoctorBuilding & input)
{
    TileBase = input.TileBase;
    Type = input.Type;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;
}

DoctorBuilding::DoctorBuilding(TileMap * input)
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


DoctorBuilding::~DoctorBuilding()
{
    if (DrawData.Built == 1) RemovalPass();
}

DoctorBuilding& DoctorBuilding::operator=(const DoctorBuilding & input)
{
    if (this == &input) return *this;

    Type = input.Type;
    TileBase = input.TileBase;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;

    return *this;
}

bool DoctorBuilding::CheckResources()
{
    if (Resources->Ducats < 350 || Resources->EducationFactor < 0.3 || Resources->Bricks < 180) return false;
    return true;
}

void DoctorBuilding::ResourceUpdateTick()
{
    if (DrawData.Built == 1) {
        UpdateBuildingGameData();
		if (Resources->Ducats > 15 && Resources->EducationFactor >= 0.3)
		{
			Resources->AddDucats(-15, false);
			UpdateArea(1);
		}
    }
}

void DoctorBuilding::BuildCost()
{
    if (DrawData.Built == 1) {
		Resources->AddDucats(-350, true);
		Resources->AddBricks(-180, true);
    }
}

void DoctorBuilding::RemovalPass()
{
	Resources->AddDucats(175, true);
	Resources->AddBricks(90, true);
}

void DoctorBuilding::SetupBuildingDatabyType()
{
    Type = Doctor;
    GameData.PopReq = 6;
    DrawData.BuildingSizeX = 3;
    DrawData.BuildingSizeY = 3;
    DrawData.SpriteOffsetX = 0;
    DrawData.SpriteOffsetY = 68;
    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getDoctorTexture());
}

void DoctorBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{

}


void DoctorBuilding::UpdateArea(bool a)
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
				Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addHealth(int(8 * a));
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