#include "Building.h"
#include <algorithm>

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
	DrawData.AutoDrawSprite = true;
	GameData.PopReq = 0;
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
    if (DrawData.Built == 1)
    {
        for (unsigned int x = 0; x < DrawData.BuildingSizeX; x++)
        {
            for (unsigned int y = 0; y < DrawData.BuildingSizeY; y++)
            {
                TileBase[x][y]->SetBuilding(nullptr);
            }
        }
    }
    if (DrawData.Built == 0) BusyBuilding = 0;
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

BuildingDataGame& Building::getDataGame()
{
    return GameData;
}

BuildingDataDraw & Building::getDataDraw()
{
	return DrawData;
}

BuildingType Building::getType()
{
	return Type;
}

ResourceList * Building::getResources()
{
    return Resources;
}

bool Building::CheckCollision()
{
    for (unsigned int x = 0; x < DrawData.BuildingSizeX; x++)
    {
        for (unsigned int y = 0; y < DrawData.BuildingSizeY; y++)
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
    for (unsigned int x = 0; x < DrawData.BuildingSizeX; x++)
    {
        for (unsigned int y = 0; y < DrawData.BuildingSizeY; y++)
        {
            if (TileBase[x][y] != nullptr && TileBase[x][y]->CheckBuilding() == true)
            {
                CollisionSprite.setPosition((float)TileBase[x][y]->getPositionX(), (float)TileBase[x][y]->getPositionY());
                target.draw(CollisionSprite);
            }
        }
    }
}

void Building::Build(ResourceList* Resources)
{
    if (CheckCollision() == true) return;
    this->Resources = Resources;
    if (CheckResources() == false)
    {
        this->Resources = nullptr; return;
    }

    for (unsigned int x = 0; x < DrawData.BuildingSizeX; x++)
    {
        for (unsigned int y = 0; y < DrawData.BuildingSizeY; y++)
        {
            TileBase[x][y]->SetBuilding(this);
            if (Type != BuildingType::Trees && Type!=BuildingType::Marbles)
                TileBase[x][y]->setSprite(Map->getTexMngr().getDefaultTileTexture1());
        }
    }
    DrawData.Built = true;
    BusyBuilding = false;
    BuildCost();
    DrawData.Sprite.setPosition((float)TileBase[0][0]->getPositionX() - DrawData.SpriteOffsetX, (float)TileBase[0][0]->getPositionY() - DrawData.SpriteOffsetY);
}

void Building::draw(sf::RenderWindow& target)
{
    
    if (DrawData.Built == false && Map->CheckBounds())
    {
		DrawBuildingSpecific(target);
        UpdatePositionbyMouse(target);
        DrawData.Sprite.setPosition((float)TileBase[0][0]->getPositionX() - DrawData.SpriteOffsetX, (float)TileBase[0][0]->getPositionY() - DrawData.SpriteOffsetY);
        if(DrawData.AutoDrawSprite)target.draw(DrawData.Sprite);
        DrawCollision(target);
    }
    else if (DrawData.Built == true)
    {
		DrawBuildingSpecific(target);
		if (DrawData.AutoDrawSprite)target.draw(DrawData.Sprite);
    }
}

void Building::UpdatePositionbyMouse(sf::RenderWindow & target)
{
    int x, y, xadjx, yadj, xadjy;
    for (x = 0, xadjx = 0, xadjy = 0; x < (int)DrawData.BuildingSizeX; x++)
    {
        for (y = 0, yadj = 0; y < (int)DrawData.BuildingSizeY; y++)
        {
            yadj = y - x;
            if (Map->checkCurrentTileAdj(x + xadjy - xadjx, yadj))
            {
                TileBase[x][y] = Map->getCurrentTileAdj(x + xadjy - xadjx, yadj);
            }
            else
            {
                TileBase[x][y] = nullptr;
            }
            if ((abs(Map->getCurrentTileY() + y - x)) % 2 == 1) xadjy++;
        }
        xadjy = 0;
        if ((abs(Map->getCurrentTileY() - x)) % 2 == 0) xadjx++;
    }
}

bool Building::CheckBusy()
{
    return BusyBuilding;
}

void Building::UpdateBuildingGameData()
{
    int mod = 3;
    bool water = false;
    int TileCount = DrawData.BuildingSizeX*DrawData.BuildingSizeY;
    double HappinessSum = 0;
    double PublicOrderSum = 0;
    double HealthSum = 0;

    for (unsigned int x = 0; x < DrawData.BuildingSizeX; x++)
    {
        for (unsigned int y = 0; y < DrawData.BuildingSizeY; y++)
        {
            if (TileBase[x][y]->getWaterAccess() == true) water = true;
            HappinessSum += TileBase[x][y]->getHappiness();
            PublicOrderSum += TileBase[x][y]->getPublicOrder();
            HealthSum += TileBase[x][y]->getHealth();

        }
    }
    GameData.WaterAccess = water;
    HappinessSum /= TileCount;
    PublicOrderSum /= TileCount;
    HealthSum /= TileCount;
    double tPublicOrderSum = PublicOrderSum;
    PublicOrderSum -= mod - (mod * (HappinessSum / 100));
    HappinessSum -= 2 *(mod - (mod * (tPublicOrderSum / 100)));
    HappinessSum -= mod - (mod * (HealthSum / 100));
	HappinessSum -= 2 * mod*Resources->FoodPenalty;
	HealthSum -= 2 * mod*Resources->FoodPenalty;
    if (Resources->Population > 0.75*Resources->PopulationCap && Resources->PopulationCap != 0 && Resources->Population <= Resources->PopulationCap)
    {
        HappinessSum -= mod * ((((Resources->PopulationCap - Resources->Population) / Resources->PopulationCap)));
        PublicOrderSum -= mod * ((((Resources->PopulationCap - Resources->Population) / Resources->PopulationCap)));
        HealthSum -= mod * ((((Resources->PopulationCap - Resources->Population) / Resources->PopulationCap)));
    }
	else if (Resources->Population > Resources->PopulationCap && Resources->PopulationCap != 0)
	{
		HappinessSum -= mod * ((((Resources->Population - 0.75*Resources->PopulationCap) / Resources->PopulationCap)) - 0.75);
		PublicOrderSum -= mod * ((((Resources->Population - 0.75*Resources->PopulationCap) / Resources->PopulationCap)) - 0.75);
		HealthSum -= mod * ((((Resources->Population - 0.75*Resources->PopulationCap) / Resources->PopulationCap)) - 0.75);
	}
    if (water == false)
    {
        HealthSum -= mod;
        HappinessSum -= mod;
    }
    GameData.Happiness = (unsigned int)fmin(100, fmax(0, HappinessSum));
    GameData.PublicOrder = (unsigned int)fmin(100, fmax(0, PublicOrderSum));
    GameData.Health = (unsigned int)fmin(100, fmax(0, HealthSum));

    for (unsigned int x = 0; x < DrawData.BuildingSizeX; x++)
    {
        for (unsigned int y = 0; y < DrawData.BuildingSizeY; y++)
        {
            TileBase[x][y]->setHappiness(GameData.Happiness);
            TileBase[x][y]->setHealth(GameData.Health);
            TileBase[x][y]->setPublicOrder(GameData.PublicOrder);
        }
    }
    double a = 0.4 * (1 - ((double)GameData.Happiness / 100));
    double b = 0.4 * (1 - ((double)GameData.PublicOrder / 100));
    double c = 0.2 * (1 - ((double)GameData.Health / 100));
    GameData.ResourceMod = 1 * (1 - a) * (1 - b) * (1 - c);
}

int Building::getPopReq()
{
	return GameData.PopReq;
}

sf::Vector3f Building::GetLocation3f()
{
	if (DrawData.Built == true) return sf::Vector3f((float)TileBase[DrawData.BuildingSizeX/2][DrawData.BuildingSizeY/2]->getPositionX(), (float)TileBase[DrawData.BuildingSizeX / 2][DrawData.BuildingSizeY / 2]->getPositionY(), 0.f);
	else return sf::Vector3f(0.f,0.f,0.f);
}
