#include "Marble.h"
#include <random>

Marble::Marble()
    : Building()
{

}

Marble::Marble(const Marble & input)
{
    TileBase = input.TileBase;
    Type = input.Type;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;
}

Marble::Marble(TileMap * input, Tile* baseTile, ResourceList* RM)
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
            TileBase[x][y] = baseTile;
        }
    }

    if (StaticSpriteSet == 0)
    {
        StaticSpriteSet = 1;
        CollisionSprite = sf::Sprite(Map->getTexMngr().getCollisionTexture());
        BlueOverlaySprite = sf::Sprite(Map->getTexMngr().getBlueOverlayTexture());
    }
    Build(RM);
}


Marble::~Marble()
{
    if (DrawData.Built == 1) RemovalPass();
}

Marble& Marble::operator=(const Marble& input)
{
    if (this == &input) return *this;

    Type = input.Type;
    TileBase = input.TileBase;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;

    return *this;
}

bool Marble::CheckResources()
{
    return true;
}

void Marble::ResourceUpdateTick()
{

}

void Marble::BuildCost()
{
}

void Marble::RemovalPass()
{
}

void Marble::SetupBuildingDatabyType()
{
    Type = BuildingType::Marbles;
    DrawData.BuildingSizeX = 1;
    DrawData.BuildingSizeY = 1;
    DrawData.SpriteOffsetX = 2;
    DrawData.SpriteOffsetY = 2;

    //std::random_device dev;
    //std::mt19937 rng(dev());
    //std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 2); // distribution in range [1, 6]

    //switch (dist6(rng))
    //{
    //case 0:
    //    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getTreeTexture());
    //    break;
    //case 1:
    //    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getTreeTexture2());
    //    break;
    //case 2:
    //    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getTreeTexture3());
    //    break;
    //}
    DrawData.Sprite = sf::Sprite(Map->getTexMngr().getMarbleTexture());
}

void Marble::DrawBuildingSpecific(sf::RenderWindow & target)
{
}
