#ifndef __WNW_TileMapClass_
#define __WNW_TileMapClass_

#include "Tile.h"
#include <algorithm>
#include <iostream>

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
	TextureManager TexMngr;
	sf::Vector2i mousePosition;

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
	TextureManager& getTexMngr();

	//Overloads//
	TileMap& operator=(const TileMap &input);

	//DataSetup//
	void BuildTileMap();
    void update(sf::Window& window);

    //Mouse
    bool MouseChecker(int mouseposx, int mouseposy, int tileposx, int tileposy);
    int OptimisedChecker(int mouseposx, int mouseposy);

	//Draw//
	void draw(sf::RenderTarget& target);
};

#endif