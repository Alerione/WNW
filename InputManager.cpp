#include "InputManager.h"



InputManager::InputManager(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT)
	:IM1(nullptr)
	,BManager(nullptr)
	,Map(nullptr)
	,RManager(nullptr)
	, mousePos{}
	,mousePosf{}
	, SCR_WIDTH(SCR_WIDTH)
	, SCR_HEIGHT(SCR_HEIGHT)
{
}

InputManager::InputManager(TileMap * m, BuildingManager * b, InterfaceManager * i, ResourceManager * r,unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT)
	:IM1(i)
	,BManager(b)
	,Map(m)
	,RManager(r)
	, mousePos{}
	, mousePosf{}
	, SCR_WIDTH(SCR_WIDTH)
	, SCR_HEIGHT(SCR_HEIGHT)
{
}

InputManager::InputManager(const InputManager & org)
	:IM1(org.IM1)
	, BManager(org.BManager)
	, Map(org.Map)
	, RManager(org.RManager)
	, mousePos(org.mousePos)
	, mousePosf(org.mousePos)
	, SCR_WIDTH(org.SCR_WIDTH)
	, SCR_HEIGHT(org.SCR_HEIGHT)
{
}


InputManager::~InputManager()
{
}

void InputManager::ReadEvent(sf::RenderWindow& window, sf::View& view)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosf = sf::Vector2f((float)mousePos.x, (float)mousePos.y);
	sf::Event event;
	if (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
			{

				if (Building::CheckBusy() == true && Map->CheckBounds())
				{
					BManager->BuildingsList.back()->Build(RManager->GetResources());
                    if (Building::CheckBusy() == false)
                        std::sort(BManager->BuildingsList.begin(), BManager->BuildingsList.end(), Building::sort);
				}
                else if(Map->CheckBounds())
                {
                    IM1->infoBarAction(*IM1, Map->getCurrentTile().getBuilding());
                }
				IM1->clickedUpdateInterface(mousePosf, *IM1);
			}
			if (event.key.code == sf::Mouse::Right)
			{

				if (Building::CheckBusy() == true)
				{
					delete BManager->BuildingsList.back();

					BManager->BuildingNum--;
					BManager->BuildingsList.resize(BManager->BuildingNum);
				}
				else
				{
					IM1->infoBarAction(*IM1, nullptr);
				}
				//IM1->clickedUpdateInterface(mousePosf, *IM1);
			}

		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
            if (event.key.code == sf::Keyboard::B)
            {
                if (Building::CheckBusy() == false)
                {
                    BManager->BuildingNum++;
                    BManager->BuildingsList.resize(BManager->BuildingNum);
                    BManager->BuildingsList.back() = new BarracksBuilding(Map);
                }
            }
			if (event.key.code == sf::Keyboard::C)
			{
				view.setCenter(float(SCR_WIDTH * 0.5), float(SCR_HEIGHT * 0.4));
				window.setView(view);
			}
			if (event.key.code == sf::Keyboard::F)
			{
				if (Building::CheckBusy() == false)
				{
					BManager->BuildingNum++;
					BManager->BuildingsList.resize(BManager->BuildingNum);
					BManager->BuildingsList.back() = new FarmBuilding(Map);
				}
			}
			if (event.key.code == sf::Keyboard::G)
			{
				if (Building::CheckBusy() == false)
				{
					BManager->BuildingNum++;
					BManager->BuildingsList.resize(BManager->BuildingNum);
					BManager->BuildingsList.back() = new MerchantGuildBuilding(Map);
				}
			}
			if (event.key.code == sf::Keyboard::H)
			{
				if (Building::CheckBusy() == false)
				{
					BManager->BuildingNum++;
					BManager->BuildingsList.resize(BManager->BuildingNum);
					BManager->BuildingsList.back() = new HorseBreederBuilding(Map);
				}
			}
			if (event.key.code == sf::Keyboard::L)
			{
				if (Building::CheckBusy() == false)
				{
					BManager->BuildingNum++;
					BManager->BuildingsList.resize(BManager->BuildingNum);
					BManager->BuildingsList.back() = new LumberBuilding(Map);
				}
			}
			if (event.key.code == sf::Keyboard::M)
			{
				view.setCenter(float(Map->getColumns() * 32), float(Map->getRows() * 8));
				window.setView(view);
			}
			if (event.key.code == sf::Keyboard::Q)
			{
				if (Building::CheckBusy() == false)
				{
					BManager->BuildingNum++;
					BManager->BuildingsList.resize(BManager->BuildingNum);
					BManager->BuildingsList.back() = new QuarryBuilding(Map);
				}
			}
			if (event.key.code == sf::Keyboard::S)
			{
				if (Building::CheckBusy() == false)
				{
					BManager->BuildingNum++;
					BManager->BuildingsList.resize(BManager->BuildingNum);
					BManager->BuildingsList.back() = new SawmillBuilding(Map);
				}
			}
			if (event.key.code == sf::Keyboard::T)
			{
				if (Building::CheckBusy() == false)
				{
					BManager->BuildingNum++;
					BManager->BuildingsList.resize(BManager->BuildingNum);
					BManager->BuildingsList.back() = new TavernBuilding(Map);
				}
			}
			if (event.key.code == sf::Keyboard::U)
			{
				if (Building::CheckBusy() == false)
				{
					BManager->BuildingNum++;
					BManager->BuildingsList.resize(BManager->BuildingNum);
					BManager->BuildingsList.back() = new HouseBuilding(Map);
				}
			}
			if (event.key.code == sf::Keyboard::W)
			{
				if (Building::CheckBusy() == false)
				{
					BManager->BuildingNum++;
					BManager->BuildingsList.resize(BManager->BuildingNum);
					BManager->BuildingsList.back() = new WellBuilding(Map);
				}
			}
			if (event.key.code == sf::Keyboard::Y)
			{
				if (Building::CheckBusy() == false)
				{
					BManager->BuildingNum++;
					BManager->BuildingsList.resize(BManager->BuildingNum);
					BManager->BuildingsList.back() = new ClayMineBuilding(Map);
				}
			}
		}

	}
	if (mousePos.x <= 10 && view.getCenter().x > view.getSize().x/4)
	{
		view.setCenter(view.getCenter().x - 8.0f, view.getCenter().y);
		window.setView(view);
	}
	if (mousePos.x >= (int)SCR_WIDTH - 10 && view.getCenter().x < Map->getColumns()*64-view.getSize().x / 4)
	{
		view.setCenter(view.getCenter().x + 8.0f, view.getCenter().y);
		window.setView(view);
	}
	if (mousePos.y <= 10 && view.getCenter().y > view.getSize().y / 4)
	{
		view.setCenter(view.getCenter().x, view.getCenter().y - 8.0f);
		window.setView(view);
	}
	if (mousePos.y >= (int)SCR_HEIGHT - 10 && view.getCenter().y < Map->getRows() * 16 - view.getSize().y / 4)
	{
		view.setCenter(view.getCenter().x, view.getCenter().y + 8.0f);
		window.setView(view);
	}
}

sf::Vector2i InputManager::getmousePos()
{
	return mousePos;
}

sf::Vector2f InputManager::getmousePosf()
{
	return mousePosf;
}

InputManager & InputManager::operator=(const InputManager & input)
{
	if (this == &input) return *this;

	IM1 = input.IM1;
	BManager = input.BManager;
	Map = input.Map;
	RManager = input.RManager;
	mousePos = input.mousePos;
	mousePosf = input.mousePosf;
	SCR_WIDTH = input.SCR_WIDTH;
	SCR_HEIGHT = input.SCR_HEIGHT;

	return *this;
}
