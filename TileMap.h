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
struct CurrentTilebyMouse
{
	int x;
	int y;
	bool bounds;
};


class TileMap
{
protected:
	//Variables//
	std::vector<std::vector<Tile>> TileArray;
	MapSize TileMapSize;
	TextureManager TexMngr;
	sf::Vector2i mousePosition;
	CurrentTilebyMouse CurTile;

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
	Tile& getCurrentTile();
	bool checkCurrentTileAdj(int AdjustX, int AdjustY);
	bool CheckBounds();
	Tile* getCurrentTileAdj(int AdjustX, int AdjustY);
	int getCurrentTileX();
	int getCurrentTileY();
	TextureManager& getTexMngr();

	//Overloads//
	TileMap& operator=(const TileMap &input);

	//DataSetup//
	void BuildTileMap();
    void update(sf::RenderWindow& window);

    //Mouse
    bool MouseChecker(int mouseposx, int mouseposy, int tileposx, int tileposy);
    int OptimisedChecker(int mouseposx, int mouseposy);

    //Check tile adj
    bool checkTileAdj(int x, int y, int AdjustX, int AdjustY);
    Tile* getTileAdj(int x, int y, int AdjustX, int AdjustY);


	//Draw//
	void draw(sf::RenderTarget& target);
};

#endif