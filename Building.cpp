#include "Building.h"



Building::Building()
	: TileBase{}
	, Type(Unspecified)
	, DrawData{}
	, GameData{}
{
}

Building::Building(const Building & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
}


Building::~Building()
{
}

Building & Building::operator=(const Building & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;

	return *this;
}
