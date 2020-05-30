#include "Tile.h"


Tile::Tile()
	: Data{ 0,0,60,60,80 }
	, Sprite()
	, TileBuilding(nullptr)
	, TilePos{ 0,0,0 }
	, TexMngr(nullptr)
	, TileID(0)
{
	updateSpritePos();
}

Tile::Tile(const sf::Sprite & sprite, Position pos, TextureManager* address, int ID)
	: Data{ 0,0,60,60,80 }
	, Sprite(sprite)
	, TileBuilding(nullptr)
	, TilePos(pos)
	, TexMngr(address)
	, TileID(ID)
{
	updateSpritePos();
}

Tile::Tile(const sf::Sprite & sprite, int posX, int posY, int posZ, TextureManager* address, int ID)
	: Data{ 0,0,60,60,80 }
	, Sprite(sprite)
	, TileBuilding(nullptr)	
	, TilePos{posX,posY,posZ}
	, TexMngr(address)
	, TileID(ID)
{
	updateSpritePos();
}

Tile::Tile(const sf::Texture & texture, Position pos, TextureManager* address, int ID)
	: Data{ 0,0,60,60,80 }
	, Sprite(texture)
	, TileBuilding(nullptr)
	, TilePos(pos)
	, TexMngr(address)
	, TileID(ID)
{
	updateSpritePos();
}

Tile::Tile(const sf::Texture & texture, int posX, int posY, int posZ, TextureManager* address, int ID)
	: Data{ 0,0,60,60,80 }
	, Sprite(texture)
	, TileBuilding(nullptr)
	, TilePos{ posX,posY,posZ }
	, TexMngr(address)
	, TileID(ID)
{
	updateSpritePos();
}
 

Tile::~Tile()
{
}

bool Tile::setWaterAccess(bool input)
{
	Data.WaterAccess = input;
	return Data.WaterAccess;
}

bool Tile::setRoadAccess(bool input)
{
	Data.RoadAccess = input;
	return Data.RoadAccess;
}

int Tile::setPublicOrder(int input)
{
	Data.PublicOrder = (int)fmax(fmin(input, 100), 0);
	return Data.PublicOrder;
}

int Tile::setHappiness(int input)
{
	Data.Happiness = (int)fmax(fmin(input, 100), 0);
	return Data.Happiness;
}

int Tile::addHappiness(int input)
{
	Data.Happiness = (int)fmax(fmin(Data.Happiness + input, 100), 0);
	return Data.Happiness;
}

int Tile::setHealth(int input)
{
	Data.Health = (int)fmax(fmin(input, 100), 0);
	return Data.Health;
}

int Tile::addHealth(int input)
{
	Data.Health = (int)fmax(fmin(Data.Health + input, 100), 0);
	return Data.Health;
}

int Tile::addPublicOrder(int input)
{
	Data.PublicOrder = (int)fmax(fmin(Data.PublicOrder + input, 100), 0);
	return Data.PublicOrder;
}

Position& Tile::setPosition(Position &input)
{
	TilePos = input;
	updateSpritePos();
	return TilePos;
}

int Tile::setHeigth(int input)
{
	TilePos.z = input;
	updateSpritePos();
	return TilePos.z;
}

int Tile::changeHeigth(int input)
{
	TilePos.z += input;
	updateSpritePos();
	return TilePos.z;
}

void Tile::setPosition(int x, int y, int z)
{
	TilePos = { x, y, z };
	updateSpritePos();
}

sf::Sprite& Tile::setSprite(sf::Texture & texture)
{
	Sprite.setTexture(texture, true);
	return Sprite;
}

void Tile::SetBuilding(Building * building)
{
	TileBuilding = building;
}

bool Tile::getWaterAccess()
{
	return Data.WaterAccess;
}

bool Tile::getRoadAccess()
{
	return Data.RoadAccess;
}

int Tile::getPublicOrder()
{
	return Data.PublicOrder;
}

int Tile::getHappiness()
{
	return Data.Happiness;
}

int Tile::getHealth()
{
	return Data.Health;
}

int Tile::getX()
{
	return (TileID-(TileID%256))/256;
}

int Tile::getY()
{
	return TileID%256;
}

Position& Tile::getPosition()
{
	return TilePos;
}

int Tile::getPositionX()
{
	return TilePos.x;
}

int Tile::getPositionY()
{
	return TilePos.y;
}

int Tile::getPositionZ()
{
	return TilePos.z;
}

sf::Sprite& Tile::getSprite()
{
	return Sprite;
}

int Tile::getID() const
{
	return TileID;
}

bool Tile::CheckBuilding()
{
	if (TileBuilding == nullptr) return false;
	return true;
}

Tile & Tile::operator=(const Tile & input)
{
	if (this == &input) return *this;
	Data = input.Data;
	Sprite = input.Sprite;
	TileBuilding = input.TileBuilding;
	TilePos = input.TilePos;
	TileID = input.TileID;
	return *this;
}

void Tile::updateSpritePos()
{
	Sprite.setPosition((float)TilePos.x, float(TilePos.y + TilePos.z - 12));
}

void Tile::draw(sf::RenderTarget & target)
{
	target.draw(Sprite);
}

Building* Tile::getBuilding()
{
    return TileBuilding;
}
