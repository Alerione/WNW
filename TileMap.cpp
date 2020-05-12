#include "TileMap.h"

TileMap::TileMap()
    : TileMapSize{ 1,1 }
    , TileArray{}
    , TexMngr()
{
}

TileMap::TileMap(MapSize size)
    : TileMapSize(size)
    , TileArray{}
    , TexMngr()
{
}

TileMap::TileMap(int columns, int rows)
    : TileMapSize{ columns, rows }
    , TileArray{}
    , TexMngr()
{
}

TileMap::TileMap(const TileMap & input)
    : TileMapSize(input.TileMapSize)
    , TileArray(input.TileArray)
    , TexMngr()
{
}


TileMap::~TileMap()
{
}

MapSize TileMap::getSize()
{
    return TileMapSize;
}

int TileMap::getRows()
{
    return TileMapSize.rows;
}

int TileMap::getColumns()
{
    return TileMapSize.columns;
}

Tile& TileMap::getTile(int x, int y)
{
    return TileArray[x][y];
}

Tile & TileMap::getCurrentTile()
{
    return TileArray[CurTile.x][CurTile.y];
}

bool TileMap::checkCurrentTileAdj(int AdjustX, int AdjustY)
{
    if (CurTile.x + AdjustX < 0 || CurTile.x + AdjustX >= TileMapSize.columns) return false;
    if (CurTile.y + AdjustY < 0 || CurTile.y + AdjustY >= TileMapSize.rows) return false;
    return true;
}

bool TileMap::CheckBounds()
{
    return CurTile.bounds;
}

Tile* TileMap::getCurrentTileAdj(int AdjustX, int AdjustY)
{
    if (CurTile.x + AdjustX < 0 || CurTile.x + AdjustX >= TileMapSize.columns) return nullptr;
    if (CurTile.y + AdjustY < 0 || CurTile.y + AdjustY >= TileMapSize.rows) return nullptr;
    return &(TileArray[CurTile.x + AdjustX][CurTile.y + AdjustY]);
}

int TileMap::getCurrentTileX()
{
    return CurTile.x;
}

int TileMap::getCurrentTileY()
{
    return CurTile.y;
}

TextureManager & TileMap::getTexMngr()
{
    return TexMngr;
}

TileMap & TileMap::operator=(const TileMap & input)
{
    if (this == &input) return *this;

    TileMapSize = input.TileMapSize;
    TileArray = input.TileArray;

    return *this;
}

void TileMap::BuildTileMap()
{
    srand(time(NULL));
    TileArray.resize(TileMapSize.columns);
    for (int x = 0; x < TileMapSize.columns; x++)
    {
        TileArray[x].resize(TileMapSize.rows);
        for (int y = 0; y < TileMapSize.rows; y++)
        {
            int tileRand = rand() % 5;
            if (tileRand == 0)
                TileArray[x][y] = Tile(TexMngr.getDefaultTileTexture(), 64 * (x)+32 * ((y) % 2), 16 * (y), 0, &TexMngr, x * 256 + y);
            else if (tileRand == 1)
                TileArray[x][y] = Tile(TexMngr.getDefaultTileTexture2(), 64 * (x)+32 * ((y) % 2), 16 * (y), 0, &TexMngr, x * 256 + y);
            else if (tileRand == 2)
                TileArray[x][y] = Tile(TexMngr.getDefaultTileTexture3(), 64 * (x)+32 * ((y) % 2), 16 * (y), 0, &TexMngr, x * 256 + y);
            else if (tileRand == 3)
                TileArray[x][y] = Tile(TexMngr.getDefaultTileTexture4(), 64 * (x)+32 * ((y) % 2), 16 * (y), 0, &TexMngr, x * 256 + y);
            else if (tileRand == 4)
                TileArray[x][y] = Tile(TexMngr.getDefaultTileTexture1(), 64 * (x)+32 * ((y) % 2), 16 * (y), 0, &TexMngr, x * 256 + y);

            
        
        }
    }
}

void TileMap::update(sf::RenderWindow& window)
{
    mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(mousePosition);
    int a = OptimisedChecker((int)worldPos.x, (int)worldPos.y);
    if (a > -1)
    {
        CurTile.bounds = true;
        CurTile.y = a % 256;
        CurTile.x = (a - (a % 256)) / 256;
    }
    else
    {
        CurTile.bounds = false;
    }
}

bool TileMap::MouseChecker(int mouseposx, int mouseposy, int tileposx, int tileposy)
{
    if (0.5*mouseposx + mouseposy < 0.5*tileposx + tileposy + 16) return 0;
    else if (0.5*mouseposx + mouseposy > 0.5*tileposx + tileposy + 48) return 0;
    else if (0.5*mouseposx - mouseposy > 0.5*tileposx - tileposy + 16) return 0;
    else if (mouseposy - 0.5*mouseposx > tileposy - 0.5*tileposx + 16) return 0;
    else return 1;
}

int TileMap::OptimisedChecker(int mouseposx, int mouseposy)
{
    for (int x = std::max(0, (mouseposx - (mouseposx % 64) - 64) / 64); x < std::min(std::max(0, (mouseposx - (mouseposx % 64) - 64) / 64) + 2, TileMapSize.columns); x++)
    {
        for (int y = std::max(0, (mouseposy - (mouseposy % 16) - 16) / 16); y < std::min(std::max(0, (mouseposy - (mouseposy % 16) - 16) / 16) + 2, TileMapSize.rows); y++)
        {
            if (MouseChecker(mouseposx, mouseposy, TileArray[x][y].getPositionX(), TileArray[x][y].getPositionY()))
            {
                return TileArray[x][y].getID();
            }
        }
    }
    return -1;
}

bool TileMap::checkTileAdj(int x, int y, int AdjustX, int AdjustY)
{
    if (x + AdjustX < 0 || x + AdjustX >= TileMapSize.columns) return false;
    if (y + AdjustY < 0 || y + AdjustY >= TileMapSize.rows) return false;
    return true;
}

Tile * TileMap::getTileAdj(int x, int y, int AdjustX, int AdjustY)
{
    if (x + AdjustX < 0 || x + AdjustX >= TileMapSize.columns) return nullptr;
    if (y + AdjustY < 0 || y + AdjustY >= TileMapSize.rows) return nullptr;
    return &(TileArray[x + AdjustX][y + AdjustY]);
}

void TileMap::draw(sf::RenderTarget & target)
{
    for (int y = 0; y < TileMapSize.rows; y++)
    {
        for (int x = 0; x < TileMapSize.columns; x++)
        {
            TileArray[x][y].draw(target);
        }
    }
}
