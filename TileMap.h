#ifndef __WNW_TileMapClass_
#define __WNW_TileMapClass_

#include "Tile.h"

struct MapSize
{
	int rows;
	int columns;
};

class TileMap
{
public:
protected:
	//Variables//
	Tile **TileArray;
	MapSize Size;

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
	Tile getTile(int x, int y);//x - column, y - row


	//Overloads//
	TileMap& operator=(const TileMap &input);

	//Draw//
	void DrawMap();//Will draw all Tiles in Array by row then column
};

#endif