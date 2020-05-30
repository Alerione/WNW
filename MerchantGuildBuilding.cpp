#include "MerchantGuildBuilding.h"

MerchantGuildBuilding::MerchantGuildBuilding()
	: Building()
{
}

MerchantGuildBuilding::MerchantGuildBuilding(const MerchantGuildBuilding & input)
{
	TileBase = input.TileBase;
	Type = input.Type;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;
}

MerchantGuildBuilding::MerchantGuildBuilding(TileMap * input)
	: Building()
{
	BusyBuilding = true;
	Map = input;
	SetupBuildingDatabyType();
	TileBase.resize(DrawData.BuildingSizeX);
	for (unsigned int x = 0; x < DrawData.BuildingSizeX; x++)
	{
		TileBase[x].resize(DrawData.BuildingSizeY);
		for (unsigned int y = 0; y < DrawData.BuildingSizeY; y++)
		{
			TileBase[x][y] = nullptr;
		}
	}
	if (StaticSpriteSet == 0)
	{
		StaticSpriteSet = 1;
		CollisionSprite = sf::Sprite(Map->getTexMngr().getCollisionTexture());
		BlueOverlaySprite = sf::Sprite(Map->getTexMngr().getBlueOverlayTexture());
	}
}


MerchantGuildBuilding::~MerchantGuildBuilding()
{
	if (DrawData.Built == 1) RemovalPass();
}

MerchantGuildBuilding& MerchantGuildBuilding::operator=(const MerchantGuildBuilding & input)
{
	if (this == &input) return *this;

	Type = input.Type;
	TileBase = input.TileBase;
	DrawData = input.DrawData;
	GameData = input.GameData;
	Map = input.Map;

	return *this;
}

bool MerchantGuildBuilding::CheckResources()
{
	if (Resources->Ducats < 200 || Resources->Planks < 200) return false;
	return true;
}

void MerchantGuildBuilding::ResourceUpdateTick()
{
	if (DrawData.Built == 1) {
		UpdateBuildingGameData();
		Resources->Ducats += (unsigned int)(25 * GameData.ResourceMod * Resources->PopMod);
	}
}

void MerchantGuildBuilding::BuildCost()
{
	Resources->Ducats -= 200;
	Resources->Prev_Ducats -= 200;
	Resources->Planks -= 200;
	Resources->Prev_Planks -= 200;
}

void MerchantGuildBuilding::RemovalPass()
{
	Resources->Ducats += 100;
	Resources->Prev_Ducats += 100;
	Resources->Planks += 100;
	Resources->Prev_Planks += 100;
}

void MerchantGuildBuilding::SetupBuildingDatabyType()
{
	Type = MerchantGuild;
	GameData.PopReq = 20;
	DrawData.BuildingSizeX = 3;
	DrawData.BuildingSizeY = 3;
	DrawData.SpriteOffsetX = 0;
	DrawData.SpriteOffsetY = 110;
	DrawData.Sprite = sf::Sprite(Map->getTexMngr().getMerchantGuildTexture());
}

void MerchantGuildBuilding::DrawBuildingSpecific(sf::RenderWindow & target)
{
}
