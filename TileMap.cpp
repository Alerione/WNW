#include "TileMap.h"

TileMap::TileMap()
	: TileMapSize{1,1}
	, TileArray{}
{
	deftex.loadFromFile("tile.png");
}

TileMap::TileMap(MapSize size)
	: TileMapSize(size)
	, TileArray{}
{
	deftex.loadFromFile("tile.png");
}

TileMap::TileMap(int columns, int rows)
	: TileMapSize{columns, rows}
	, TileArray{}
{
	deftex.loadFromFile("tile.png");
}

TileMap::TileMap(const TileMap & input)
	: TileMapSize(input.TileMapSize)
	, TileArray(input.TileArray)
{
	deftex.loadFromFile("tile.png");
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
			TileArray[x][y] = Tile(deftex, 64 * (x)+32 * ((y) % 2), 16 * (y), 0);
		}
	}
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
