#include "Building.h"

bool Building::BusyBuilding = 0;
sf::Sprite Building::CollisionSprite = sf::Sprite();
sf::Sprite Building::BlueOverlaySprite = sf::Sprite();
bool Building::StaticSpriteSet = 0;

Building::Building()
	: TileBase{}
	, Type(Unspecified)
	, DrawData{}
	, GameData{}
	, Map(nullptr)
{

}

Building::Building(const Building & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
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
	Map = input.Map;

	return *this;
}


bool Building::CheckCollision()
{
	for (int x = 0; x < DrawData.BuildingSizeX; x++)
	{
		for (int y = 0; y < DrawData.BuildingSizeY; y++)
		{
			if (TileBase[x][y] == nullptr || TileBase[x][y]->CheckBuilding() == true)
			{
				return true;
			}
		}
	}
	return false;
}

void Building::DrawCollision(sf::RenderTarget & target)
{
	for (int x = 0; x < DrawData.BuildingSizeX; x++)
	{
		for (int y = 0; y < DrawData.BuildingSizeY; y++)
		{
			if (TileBase[x][y] != nullptr && TileBase[x][y]->CheckBuilding() == true)
			{
				CollisionSprite.setPosition(TileBase[x][y]->getPositionX(), TileBase[x][y]->getPositionY());
				target.draw(CollisionSprite);
			}
		}
	}
}

void Building::Build()
{
	if (CheckCollision() == true) return;

	for (int x = 0; x < DrawData.BuildingSizeX; x++)
	{
		for (int y = 0; y < DrawData.BuildingSizeY; y++)
		{
			TileBase[x][y]->SetBulding(this);
		}
	}
	DrawData.Built = true;
	BusyBuilding = false;
	DrawData.Sprite.setPosition(TileBase[0][0]->getPositionX()-DrawData.SpriteOffsetX, TileBase[0][0]->getPositionY()-DrawData.SpriteOffsetY);
}

void Building::draw(sf::RenderWindow& target)
{
	if (DrawData.Built == false)
	{
		UpdatePositionbyMouse(target);
		DrawData.Sprite.setPosition(TileBase[0][0]->getPositionX()-DrawData.SpriteOffsetX, TileBase[0][0] ->getPositionY() - DrawData.SpriteOffsetY);
		target.draw(DrawData.Sprite);
		DrawCollision(target);
	}
	else
	{
		target.draw(DrawData.Sprite);
	}
	DrawBuildingSpecific(target);
}

void Building::UpdatePositionbyMouse(sf::RenderWindow & target)
{
	int x, y, xadjx, yadj, xadjy;
	for (x = 0, xadjx = 0, xadjy=0; x < DrawData.BuildingSizeX;x++)
	{
		for (y = 0, yadj = 0; y < DrawData.BuildingSizeY; y++)
		{
			yadj = y - x;
			if (Map->checkCurrentTileAdj(x+xadjy-xadjx, yadj))
			{
				TileBase[x][y] = Map->getCurrentTileAdj(x+xadjy - xadjx, yadj);
			}
			else
			{
				TileBase[x][y] = nullptr;
			}
			if ((Map->getCurrentTileY() + y - x) % 2 == 1) xadjy++;
		}
		xadjy = 0;
		if((Map->getCurrentTileY() - x )% 2 == 0) xadjx++;
	}
}

bool Building::CheckBusy()
{
	return BusyBuilding;
}
