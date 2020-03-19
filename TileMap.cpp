#include "TileMap.h"



TileMap::TileMap()
{
}

TileMap::TileMap(MapSize size)
	: TileMapSize(size)
	, TileArray{}
{
}

TileMap::TileMap(int rows, int columns)
	: TileMapSize{rows, columns}
	, TileArray{}
{
}

TileMap::TileMap(const TileMap & input)
	: TileMapSize(input.TileMapSize)
	, TileArray(input.TileArray)
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

TileMap & TileMap::operator=(const TileMap & input)
{
	if (this == &input) return *this;

	TileMapSize = input.TileMapSize;
	TileArray = input.TileArray;

	return *this;
}

void TileMap::DrawMap(sf::RenderTarget& target, sf::RenderStates states)
{
	for (int y = 0; y < TileMapSize.rows; y++)
	{
		for (int x = 0; x < TileMapSize.columns; x++)
		{
			TileArray[y][x].draw(target, states);
		}
	}
}
