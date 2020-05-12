#include "Tree.h"
#include <random>

Tree::Tree()
    : Building()
{

}

Tree::Tree(const Tree & input)
{
    TileBase = input.TileBase;
    Type = input.Type;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;
}

Tree::Tree(TileMap * input, Tile* baseTile, ResourceList* RM)
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


Tree::~Tree()
{
    if (DrawData.Built == 1) RemovalPass();
}

Tree& Tree::operator=(const Tree & input)
{
    if (this == &input) return *this;

    Type = input.Type;
    TileBase = input.TileBase;
    DrawData = input.DrawData;
    GameData = input.GameData;
    Map = input.Map;

    return *this;
}

bool Tree::CheckResources()
{
    return true;
}

void Tree::ResourceUpdateTick()
{

}

void Tree::BuildCost()
{
}

void Tree::RemovalPass()
{
}

void Tree::SetupBuildingDatabyType()
{
    Type = BuildingType::Trees;
    DrawData.BuildingSizeX = 1;
    DrawData.BuildingSizeY = 1;
    DrawData.SpriteOffsetX = 0;
    DrawData.SpriteOffsetY = 80;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 2); // distribution in range [1, 6]

    switch (dist6(rng))
    {
    case 0:
        DrawData.Sprite = sf::Sprite(Map->getTexMngr().getTreeTexture());
        break;
    case 1:
        DrawData.Sprite = sf::Sprite(Map->getTexMngr().getTreeTexture2());
        break;
    case 2:
        DrawData.Sprite = sf::Sprite(Map->getTexMngr().getTreeTexture3());
        break;
    }
}

void Tree::DrawBuildingSpecific(sf::RenderWindow & target)
{
}
