#include "TileMap.h"

TileMap::TileMap()
	: TileMapSize{1,1}
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
	: TileMapSize{columns, rows}
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
	TileArray.resize(TileMapSize.columns);
	for (int x = 0; x < TileMapSize.columns; x++)
	{
		TileArray[x].resize(TileMapSize.rows);
		for (int y = 0; y < TileMapSize.rows; y++)
		{
			TileArray[x][y] = Tile(TexMngr.getDefaultTileTexture(), 64 * (x)+32 * ((y) % 2), 16 * (y), 0, &TexMngr, x*256+y);
		}
	}
}

void TileMap::update(sf::Window& window)
{
	mousePosition = sf::Mouse::getPosition(window);
	int a = OptimisedChecker(mousePosition.x, mousePosition.y);
	if(a>-1) std::cout << a << std::endl;
	/*bool end = 0;
	for (int x = 0; (x < TileMapSize.columns) & end == 0; x++)
    {
        for (int y = 0; (y < TileMapSize.rows) & end == 0 ; y++)
        {
            if (MouseChecker(mousePosition.x, mousePosition.y, TileArray[x][y].getPositionX(), TileArray[x][y].getPositionY()))
            {
                std::cout << "Tile ID of Tile [" << x << "][" << y << "] is " << TileArray[x][y].getID() << std::endl;
				end = 1;
            }
        }
    }*/
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
    for (int x = std::max(0, (mouseposx - (mouseposx % 64) - 64) / 64); x < std::min(std::max(0, (mouseposx - (mouseposx % 64) - 64) / 64) + 2,TileMapSize.columns); x++)
    {
        for (int y = std::max(0, (mouseposy - (mouseposy % 16) - 16) / 16); y < std::min(std::max(0, (mouseposy - (mouseposy % 16) - 16) / 16) + 2,TileMapSize.rows); y++)
        {
			if (MouseChecker(mouseposx, mouseposy, TileArray[x][y].getPositionX(), TileArray[x][y].getPositionY()))
			{
				return TileArray[x][y].getID();
			}
        }
    }
	return -1;
}

void TileMap::draw(sf::RenderTarget & target)
{
	Tile a;
	for (int y = 0; y < TileMapSize.rows; y++)
	{
		for (int x = 0; x < TileMapSize.columns; x++)
		{
			TileArray[x][y].draw(target);
		}
	}
}
