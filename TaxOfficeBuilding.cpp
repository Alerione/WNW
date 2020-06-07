#include "TaxOfficeBuilding.h"


TaxOfficeBuilding::TaxOfficeBuilding()
    : Building()
{
}

TaxOfficeBuilding::TaxOfficeBuilding(const TaxOfficeBuilding & input)
{
    TileBase = input.TileBase;
    Type = input.Type;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;
}

TaxOfficeBuilding::TaxOfficeBuilding(TileMap * input)
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


TaxOfficeBuilding::~TaxOfficeBuilding()
{
    if (DrawData.Built == 1) RemovalPass();
}

TaxOfficeBuilding& TaxOfficeBuilding::operator=(const TaxOfficeBuilding & input)
{
    if (this == &input) return *this;

    Type = input.Type;
    TileBase = input.TileBase;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;

    return *this;
}

bool TaxOfficeBuilding::CheckResources()
{
    if (Resources->Ducats < 300 || Resources->Bricks< 200 || Resources->EducationFactor < 0.25) return false;
    return true;
}

void TaxOfficeBuilding::ResourceUpdateTick()
{
    if (DrawData.Built == 1) {
        UpdateBuildingGameData();
		if(Resources->EducationFactor >= 0.25)Resources->Ducats += (unsigned int)(4 * TaxArea());
    }
}

void TaxOfficeBuilding::BuildCost()
{
    if (DrawData.Built == 1) {
		Resources->AddDucats(-300, true);
		Resources->AddBricks(-200, true);
    }
}

void TaxOfficeBuilding::RemovalPass()
{
	Resources->AddDucats(150, true);
	Resources->AddBricks(100, true);
}

void TaxOfficeBuilding::SetupBuildingDatabyType()
{
    Type = TaxOffice;
    GameData.PopReq = 20;
    DrawData.BuildingSizeX = 2;
    DrawData.BuildingSizeY = 2;
    DrawData.SpriteOffsetX = 0;
    DrawData.SpriteOffsetY = 68;
    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getTaxOfficeTexutre());
}

void TaxOfficeBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{

}


int TaxOfficeBuilding::TaxArea()
{
	int a = 0;
	int Range = 6;
	int x, y, xadjx, yadj, xadjy;
	for (x = -Range, xadjx = 0, xadjy = 0; x < Range + (int)DrawData.BuildingSizeX; x++)
	{
		for (y = 0, yadj = 0; y < 2 * Range + (int)DrawData.BuildingSizeY; y++)
		{
			yadj = y - x - Range;
			if (Map->checkTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj))
			{
				if (Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->CheckBuilding() != false)
				{
					if (Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->getBuilding()->getType() == House) 
					{ 
						Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addPublicOrder(-4);
						a++; 
					}
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
