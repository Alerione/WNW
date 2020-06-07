#include "BrickMakerBuilding.h"


BrickMakerBuilding::BrickMakerBuilding()
    : Building()
{
}

BrickMakerBuilding::BrickMakerBuilding(const BrickMakerBuilding & input)
{
    TileBase = input.TileBase;
    Type = input.Type;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;
}

BrickMakerBuilding::BrickMakerBuilding(TileMap * input)
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


BrickMakerBuilding::~BrickMakerBuilding()
{
    if (DrawData.Built == 1) RemovalPass();
}

BrickMakerBuilding& BrickMakerBuilding::operator=(const BrickMakerBuilding & input)
{
    if (this == &input) return *this;

    Type = input.Type;
    TileBase = input.TileBase;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;

    return *this;
}

bool BrickMakerBuilding::CheckResources()
{
    if (Resources->Ducats < 75 || Resources->Planks < 100) return false;
    return true;
}

void BrickMakerBuilding::ResourceUpdateTick()
{
    if (DrawData.Built == 1) {
        UpdateBuildingGameData();
		if (Resources->Clay >= 20 * GameData.ResourceMod * Resources->PopMod)
		{
			Resources->Clay -= (int)(20 * GameData.ResourceMod * Resources->PopMod);
			Resources->Bricks += (int)(10 * GameData.ResourceMod * Resources->PopMod);
		}
    }
}

void BrickMakerBuilding::BuildCost()
{
    if (DrawData.Built == 1) {
		Resources->AddDucats(-75, true);
		Resources->AddPlanks(-100, true);
    }
}

void BrickMakerBuilding::RemovalPass()
{
	Resources->AddDucats(37, true);
	Resources->AddPlanks(50, true);
}

void BrickMakerBuilding::SetupBuildingDatabyType()
{
    Type = BrickMaker;
    GameData.PopReq = 5;
    DrawData.BuildingSizeX = 3;
    DrawData.BuildingSizeY = 3;
    DrawData.SpriteOffsetX = -8;
    DrawData.SpriteOffsetY = 90;
    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getBrickMakerTexture());
}

void BrickMakerBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{

}


