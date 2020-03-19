#ifndef __WNW_TileMapClass_
#define __WNW_TileMapClass_

#include <vector>
#include "Tile.h"

struct MapSize
{
	int rows;
	int columns;
};

class TileMap
{
protected:
	//Variables//
	std::vector<std::vector<Tile>> TileArray;
	MapSize TileMapSize;

public:
	//Constructors and Destructors//
	TileMap();
	TileMap(MapSize size);
	TileMap(int rows, int columns);
	TileMap(const TileMap& input);
	virtual ~TileMap();

	//Set and Get Methods//
	MapSize getSize();
	int getRows();
	int getColumns();
	Tile& getTile(int x, int y);//x - column, y - row


	//Overloads//
	TileMap& operator=(const TileMap &input);

	//Draw//
	void DrawMap(sf::RenderTarget& target, sf::RenderStates states);//Will draw all Tiles in Array by row then column
};

#endif