#include "MarketBuilding.h"


MarketBuilding::MarketBuilding()
    : Building()
{
}

MarketBuilding::MarketBuilding(const MarketBuilding & input)
{
    TileBase = input.TileBase;
    Type = input.Type;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;
}

MarketBuilding::MarketBuilding(TileMap * input)
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


MarketBuilding::~MarketBuilding()
{
    if (DrawData.Built == 1) RemovalPass();
}

MarketBuilding& MarketBuilding::operator=(const MarketBuilding & input)
{
    if (this == &input) return *this;

    Type = input.Type;
    TileBase = input.TileBase;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;

    return *this;
}

bool MarketBuilding::CheckResources()
{
    if (Resources->Ducats < 150 || Resources->Planks < 100 ) return false;
    return true;
}

void MarketBuilding::ResourceUpdateTick()
{
    if (DrawData.Built == 1) {
        UpdateBuildingGameData();
		Resources->Ducats += (int)(30 *GameData.ResourceMod * Resources->PopMod);
    }
}

void MarketBuilding::BuildCost()
{
    if (DrawData.Built == 1) {
		Resources->AddDucats(-150, true);
		Resources->AddPlanks(-100, true);
    }
}

void MarketBuilding::RemovalPass()
{
	Resources->AddDucats(75, true);
	Resources->AddPlanks(50, true);
}

void MarketBuilding::SetupBuildingDatabyType()
{
    Type = Market;
    GameData.PopReq = 25;
    DrawData.BuildingSizeX = 3;
    DrawData.BuildingSizeY = 3;
    DrawData.SpriteOffsetX = 0;
    DrawData.SpriteOffsetY = 48;
    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getMarketTexture());
}

void MarketBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{

}


