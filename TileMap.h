#ifndef __WNW_TileMapClass_
#define __WNW_TileMapClass_

#include <vector>
#include "Tile.h"

struct MapSize
{
	int columns;
	int rows;
};


class TileMap
{
protected:
	//Variables//
	std::vector<std::vector<Tile>> TileArray;
	MapSize TileMapSize;

	//Temporary//
	sf::Texture deftex;

public:
	//Constructors and Destructors//
	TileMap();
	TileMap(MapSize size);
	TileMap(int columns, int rows);
	TileMap(const TileMap& input);
	virtual ~TileMap();

	//Set and Get Methods//
	MapSize getSize();
	int getRows();
	int getColumns();
	Tile& getTile(int x, int y);//x - column, y - row


	//Overloads//
	TileMap& operator=(const TileMap &input);

	//DataSetup//
	void BuildTileMap();

	//Draw//
	void draw(sf::RenderTarget& target);
};

#endif