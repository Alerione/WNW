#include "Tile.h"



Tile::Tile()
	: Data{ 0,0,0,0 }
	, Sprite()
	, TileBuilding(nullptr)
	, TilePos{ 0,0,0 }
	, TexMngr(nullptr)
	, TileID(0)
{
	updateSpritePos();
}

Tile::Tile(const sf::Sprite & sprite, Position pos, TextureManager* address, int ID)
	: Data{ 0,0,0,0 }
	, Sprite(sprite)
	, TileBuilding(nullptr)
	, TilePos(pos)
	, TexMngr(address)
	, TileID(ID)
{
	updateSpritePos();
}

Tile::Tile(const sf::Sprite & sprite, int posX, int posY, int posZ, TextureManager* address, int ID)
	: Data{ 0,0,0,0 }
	, Sprite(sprite)
	, TileBuilding(nullptr)	
	, TilePos{posX,posY,posZ}
	, TexMngr(address)
	, TileID(ID)
{
	updateSpritePos();
}

Tile::Tile(const sf::Texture & texture, Position pos, TextureManager* address, int ID)
	: Data{ 0,0,0,0 }
	, Sprite(texture)
	, TileBuilding(nullptr)
	, TilePos(pos)
	, TexMngr(address)
	, TileID(ID)
{
	updateSpritePos();
}

Tile::Tile(const sf::Texture & texture, int posX, int posY, int posZ, TextureManager* address, int ID)
	: Data{ 0,0,0,0 }
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
	if (TileBuilding != nullptr) delete TileBuilding;
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
	Data.PublicOrder = input;
	return Data.PublicOrder;
}

int Tile::setHappiness(int input)
{
	Data.Happiness = input;
	return Data.Happiness;
}

int Tile::addHappiness(int input)
{
	Data.Happiness += input;
	return Data.Happiness;
}

int Tile::addPublicOrder(int input)
{
	Data.PublicOrder += input;
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

int Tile::getID()
{
	return TileID;
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
	Sprite.setPosition(TilePos.x, TilePos.y + TilePos.z);
}

void Tile::draw(sf::RenderTarget & target)
{
	target.draw(Sprite);
}
