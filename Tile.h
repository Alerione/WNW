#ifndef __WNW_TileClass_
#define __WNW_TileClass_

#include <SFML/Graphics.hpp>

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
class Tile :
	public sf::Drawable, public sf::Transformable
{
protected:
	//Variables//
	TileGameData Data;
	sf::Sprite Sprite;
	Building *TileBuilding;
	int TileID;// Row(Begining with 0) * 256 + Column(Begining with 0)

public:
	//Constructors and Destructors//
	Tile();
	Tile(const sf::Sprite &sprite, Position pos);
	Tile(const sf::Sprite &sprite, int posX, int posY, int posZ);
	virtual ~Tile();

	//Set and Get Methods//
	bool setWaterAccess(bool);
	bool setRoadAccess(bool);
	int setPublicOrder(bool);
	int setHappiness(bool);
	int addHappiness(int);
	int addPublicOrder(int);
	int setPosition(Position);
	int setPosition(int, int, int);
	sf::Sprite setSprite(sf::Texture &texture);

	bool getWaterAccess();
	bool getRoadAccess();
	int getPublicOrder();
	int getHappiness();
	Position getPosition();
	int getPositionX();
	int getPositionY();
	int getPositionZ();
	sf::Sprite getSprite();
	int getID();

	//Overloads//
	Tile& operator=(const Tile &input);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //Will draw sprite at correct coords?

};

Tile& getTilebyPos

#endif

