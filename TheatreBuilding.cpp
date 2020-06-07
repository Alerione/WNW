#include "TheatreBuilding.h"


TheatreBuilding::TheatreBuilding()
    : Building()
{
}

TheatreBuilding::TheatreBuilding(const TheatreBuilding & input)
{
    TileBase = input.TileBase;
    Type = input.Type;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;
}

TheatreBuilding::TheatreBuilding(TileMap * input)
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


TheatreBuilding::~TheatreBuilding()
{
    if (DrawData.Built == 1) RemovalPass();
}

TheatreBuilding& TheatreBuilding::operator=(const TheatreBuilding & input)
{
    if (this == &input) return *this;

    Type = input.Type;
    TileBase = input.TileBase;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;

    return *this;
}

bool TheatreBuilding::CheckResources()
{
    if (Resources->Ducats < 400 || Resources->MarbleBlocks < 400 || Resources->EducationFactor < 0.7) return false;
    return true;
}

void TheatreBuilding::ResourceUpdateTick()
{
    if (DrawData.Built == 1) {
        UpdateBuildingGameData();
		if (Resources->Ducats >= 40 && Resources->EducationFactor >= 0.7)
		{
			Resources->Ducats -= 40;
			UpdateArea(1);
		}
		else if (Resources->EducationFactor < 0.7) {}
		else
		{
			UpdateArea(0);
		}
    }
}

void TheatreBuilding::BuildCost()
{
    if (DrawData.Built == 1) {
		Resources->AddDucats(-400, true);
		Resources->AddMarbleBlocks(-400, true);
    }
}

void TheatreBuilding::RemovalPass()
{
	Resources->AddDucats(200, true);
	Resources->AddMarbleBlocks(200, true);
}

void TheatreBuilding::SetupBuildingDatabyType()
{
    Type = Theatre;
    GameData.PopReq = 24;
    DrawData.BuildingSizeX = 5;
    DrawData.BuildingSizeY = 5;
    DrawData.SpriteOffsetX = 0;
    DrawData.SpriteOffsetY = 112;
    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getTheatreTexture());
}

void TheatreBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{

}


void TheatreBuilding::UpdateArea(bool money)
{
	int Range = 8;
	int x, y, xadjx, yadj, xadjy;
	for (x = -Range, xadjx = 0, xadjy = 0; x < Range + (int)DrawData.BuildingSizeX; x++)
	{
		for (y = 0, yadj = 0; y < 2 * Range + (int)DrawData.BuildingSizeY; y++)
		{
			yadj = y - x - Range;
			if (Map->checkTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj))
			{
				if(money)Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addHappiness(10);
				else Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addPublicOrder(-6);
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