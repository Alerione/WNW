#include "MarbleCutterBuilding.h"


MarbleCutterBuilding::MarbleCutterBuilding()
    : Building()
{
}

MarbleCutterBuilding::MarbleCutterBuilding(const MarbleCutterBuilding & input)
{
    TileBase = input.TileBase;
    Type = input.Type;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;
}

MarbleCutterBuilding::MarbleCutterBuilding(TileMap * input)
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


MarbleCutterBuilding::~MarbleCutterBuilding()
{
    if (DrawData.Built == 1) RemovalPass();
}

MarbleCutterBuilding& MarbleCutterBuilding::operator=(const MarbleCutterBuilding & input)
{
    if (this == &input) return *this;

    Type = input.Type;
    TileBase = input.TileBase;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;

    return *this;
}

bool MarbleCutterBuilding::CheckResources()
{
    if (Resources->Ducats < 100 || Resources->Planks < 200) return false;
    return true;
}

void MarbleCutterBuilding::ResourceUpdateTick()
{
    if (DrawData.Built == 1) {
        UpdateBuildingGameData();
		if (Resources->Marble >= 20 * GameData.ResourceMod * Resources->PopMod)
		{
			Resources->Marble -= (int)(20 * GameData.ResourceMod * Resources->PopMod);
			Resources->MarbleBlocks += (int)(10 * GameData.ResourceMod * Resources->PopMod);
		}
    }
}

void MarbleCutterBuilding::BuildCost()
{
    if (DrawData.Built == 1) {
		Resources->AddDucats(-100, true);
		Resources->AddPlanks(-200, true);
    }
}

void MarbleCutterBuilding::RemovalPass()
{
	Resources->AddDucats(50, true);
	Resources->AddPlanks(100, true);
}

void MarbleCutterBuilding::SetupBuildingDatabyType()
{
    Type = MarbleCutter;
    GameData.PopReq = 10;
    DrawData.BuildingSizeX = 3;
    DrawData.BuildingSizeY = 3;
    DrawData.SpriteOffsetX = 0;
    DrawData.SpriteOffsetY = 68;
    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getMarbleCutterTexture());
}

void MarbleCutterBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{

}


