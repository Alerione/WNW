#include "UniversityBuilding.h"


UniversityBuilding::UniversityBuilding()
    : Building()
{
}

UniversityBuilding::UniversityBuilding(const UniversityBuilding & input)
{
    TileBase = input.TileBase;
    Type = input.Type;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;
}

UniversityBuilding::UniversityBuilding(TileMap * input)
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


UniversityBuilding::~UniversityBuilding()
{
    if (DrawData.Built == 1) RemovalPass();
}

UniversityBuilding& UniversityBuilding::operator=(const UniversityBuilding & input)
{
    if (this == &input) return *this;

    Type = input.Type;
    TileBase = input.TileBase;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;

    return *this;
}

bool UniversityBuilding::CheckResources()
{
    if (Resources->Ducats < 500 || Resources->Bricks < 200 || Resources->MarbleBlocks < 200 || Resources->EducationFactor < 0.5) return false;
    return true;
}

void UniversityBuilding::ResourceUpdateTick()
{
    if (DrawData.Built == 1) {
        UpdateBuildingGameData();
		if (Resources->Ducats >= 40 && Resources->EducationFactor >= 0.5)
		{
			Resources->Ducats -= 40;
		}
		else if (Resources->EducationFactor < 0.5);
		else UpdateArea(0);
    }
}

void UniversityBuilding::BuildCost()
{
    if (DrawData.Built == 1) {
		Resources->AddDucats(-500, true);
		Resources->AddBricks(-200, true);
		Resources->AddMarbleBlocks(-200, true);
    }
}

void UniversityBuilding::RemovalPass()
{
	Resources->AddDucats(250, true);
	Resources->AddBricks(100, true);
	Resources->AddMarbleBlocks(100, true);
}

void UniversityBuilding::SetupBuildingDatabyType()
{
    Type = University;
    GameData.PopReq = 40;
    DrawData.BuildingSizeX = 4;
    DrawData.BuildingSizeY = 4;
    DrawData.SpriteOffsetX = 0;
    DrawData.SpriteOffsetY = 128;
    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getUniversityTexture());
}

void UniversityBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{

}




void UniversityBuilding::UpdateArea(bool a)
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
				if (!a)Map->getTileAdj(TileBase[0][0]->getX(), TileBase[0][0]->getY(), x + xadjy - xadjx, yadj)->addPublicOrder(int(-8));
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
