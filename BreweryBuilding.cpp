#include "BreweryBuilding.h"


BreweryBuilding::BreweryBuilding()
    : Building()
{
}

BreweryBuilding::BreweryBuilding(const BreweryBuilding & input)
{
    TileBase = input.TileBase;
    Type = input.Type;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;
}

BreweryBuilding::BreweryBuilding(TileMap * input)
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


BreweryBuilding::~BreweryBuilding()
{
    if (DrawData.Built == 1) RemovalPass();
}

BreweryBuilding& BreweryBuilding::operator=(const BreweryBuilding & input)
{
    if (this == &input) return *this;

    Type = input.Type;
    TileBase = input.TileBase;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;

    return *this;
}

bool BreweryBuilding::CheckResources()
{
    if (Resources->Ducats < 50 || Resources->Bricks < 50 || Resources->Lumber < 100) return false;
    return true;
}

void BreweryBuilding::ResourceUpdateTick()
{
    if (DrawData.Built == 1) {
        UpdateBuildingGameData();
		if (Resources->Food >= 20 * GameData.ResourceMod * Resources->PopMod)
		{
			Resources->Food -= (int)(20 * GameData.ResourceMod * Resources->PopMod);
			Resources->Beer += (int)(10 * GameData.ResourceMod * Resources->PopMod);
		}
    }
}

void BreweryBuilding::BuildCost()
{
    if (DrawData.Built == 1) {
		Resources->AddDucats(-50, true);
		Resources->AddBricks(-50, true);
		Resources->AddLumber(-100, true);
    }
}

void BreweryBuilding::RemovalPass()
{
	Resources->AddDucats(25, true);
	Resources->AddBricks(25, true);
	Resources->AddLumber(50, true);
}

void BreweryBuilding::SetupBuildingDatabyType()
{
    Type = Brewery;
    GameData.PopReq = 6;
    DrawData.BuildingSizeX = 3;
    DrawData.BuildingSizeY = 3;
    DrawData.SpriteOffsetX = -16;
    DrawData.SpriteOffsetY = 108;
    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getBreweryTexture());
}

void BreweryBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{

}


