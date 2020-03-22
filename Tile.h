#ifndef __WNW_TileClass_
#define __WNW_TileClass_

#include "TextureManager.h"

struct TileGameData
{
	bool WaterAccess;
	bool RoadAccess;
	unsigned int PublicOrder;
	unsigned int Happiness;
};
struct Position
{
	int x;
	int y;
	int z;
};
class Building;
class Tile
{
protected:
	//Variables//
	TileGameData Data;
	sf::Sprite Sprite;
	Building *TileBuilding;
	Position TilePos;
	TextureManager* TexMngr;
	int TileID;// Row(Begining with 0) * 256 + Column(Begining with 0)
	
public:
	//Constructors and Destructors//
	Tile();
	Tile(const sf::Sprite &sprite, Position pos, TextureManager* address, int ID);
	Tile(const sf::Sprite &sprite, int posX, int posY, int posZ, TextureManager* address, int ID);
	Tile(const sf::Texture &texture, Position pos, TextureManager* address, int ID);
	Tile(const sf::Texture &texture, int posX, int posY, int posZ, TextureManager* address, int ID);
	virtual ~Tile();

	//Set and Get Methods//
	bool setWaterAccess(bool);
	bool setRoadAccess(bool);
	int setPublicOrder(int);
	int setHappiness(int);
	int addHappiness(int);
	int addPublicOrder(int);
	Position& setPosition(Position&);
	int setHeigth(int);
	int changeHeigth(int);
	void setPosition(int, int, int = 0);
	sf::Sprite& setSprite(sf::Texture &texture);

	bool getWaterAccess();
	bool getRoadAccess();
	int getPublicOrder();
	int getHappiness();
	Position& getPosition();
	int getPositionX();
	int getPositionY();
	int getPositionZ();
	sf::Sprite& getSprite();
	int getID();

	//Overloads//
	Tile& operator=(const Tile &input);
	//Methods//
	void updateSpritePos();
	void draw(sf::RenderTarget& target);

};
#endif

