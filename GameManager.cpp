#include "GameManager.h"
#include <time.h> 


GameManager::GameManager()
	:BManager()
	, RManager(&BManager)
	, Map(10, 20)
	, IM1((float)1280, (float)720)
	, SCR_WIDTH(1280)
	, SCR_HEIGHT(720)
	, backgroundSprite{}
	, view{}
	, window(nullptr)
	, interfaceView{}
	, InputManager(&Map, &BManager, &IM1, &RManager)
{
	IM1.getResources(RManager.GetResources());
}


GameManager::GameManager(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT, unsigned int MapX, unsigned int MapY)
	:BManager()
	, RManager(&BManager)
	, Map(MapX, MapY)
	, IM1((float)SCR_WIDTH, (float)SCR_HEIGHT)
	, SCR_WIDTH(SCR_WIDTH)
	, SCR_HEIGHT(SCR_HEIGHT)
	, backgroundSprite{}
	, view{}
	, window(nullptr)
	, interfaceView{}
	, InputManager(&Map, &BManager, &IM1, &RManager, SCR_WIDTH, SCR_HEIGHT)
{
	IM1.getResources(RManager.GetResources());
}

GameManager::GameManager(const GameManager & input)
	:BManager(input.BManager)
	,RManager(input.RManager)
	,InputManager(input.InputManager)
	,IM1(input.IM1)
	,Map(input.Map)
	,backgroundSprite(input.backgroundSprite)
	,interfaceView(input.interfaceView)
	,view(input.view)
	,window(input.window)
	,SCR_HEIGHT(input.SCR_HEIGHT)
	,SCR_WIDTH(input.SCR_WIDTH)
{
}

GameManager::~GameManager()
{
}

void GameManager::Initialise()
{
	backgroundSprite = sf::Sprite(Map.getTexMngr().getBackgroundTexture());
	backgroundSprite.setTextureRect(sf::IntRect(0, 0, SCR_WIDTH, SCR_HEIGHT));
	double interfaceHeight = (double)SCR_HEIGHT * 0.05;
	IM1.buildInterface(interfaceHeight);
	view = sf::View(sf::Vector2f((float)SCR_WIDTH / 2, (float)SCR_HEIGHT / 2 - 2 * (float)interfaceHeight), sf::Vector2f((float)SCR_WIDTH, (float)SCR_HEIGHT - 2 * (float)interfaceHeight));
	view.setCenter(float(Map.getColumns() * 32), float(Map.getRows() * 8));
	interfaceView = sf::View(sf::Vector2f(0 + (float)SCR_WIDTH / 2, 0 + (float)SCR_HEIGHT / 2), sf::Vector2f((float)SCR_WIDTH, (float)SCR_HEIGHT));
	if(window!=nullptr)window->setMouseCursorGrabbed(1);

	Map.BuildTileMap();
}

void GameManager::grabWindow(sf::RenderWindow & window)
{
	this->window = &window;
}

void GameManager::RenderPass()
{
	InputManager.ReadEvent(*window, view);
	window->setView(interfaceView);
	window->clear(sf::Color::Black);
	window->draw(backgroundSprite);
	window->setView(view);
	Map.draw(*window);
	Map.update(*window);
	for (int build = 0; build < BManager.BuildingNum; build++)
	{
		BManager.BuildingsList[build]->draw(*window);
	}
	if (time(NULL) % 3 == 0 && timer == false) 
	{
		timer = true;
		RManager.ResourceUpdateTick();
	}
	else if (time(NULL) % 3 != 0)
	{
		timer = false;
	}
	window->setView(interfaceView);
	IM1.drawInterface(*window);
	IM1.updateInterace(InputManager.getmousePosf(), BManager.BuildingsList, Map, BManager.BuildingNum);
	IM1.updateResources();
	window->setView(view);
}

GameManager & GameManager::operator=(const GameManager & input)
{
	if (this == &input) return *this;

	BManager = input.BManager;
	InputManager = input.InputManager;
	IM1 = input.IM1;
	Map = input.Map;
	RManager = input.RManager;
	backgroundSprite = input.backgroundSprite;
	interfaceView = input.interfaceView;
	view = input.view;
	window = input.window;
	SCR_HEIGHT = input.SCR_HEIGHT;
	SCR_WIDTH = input.SCR_WIDTH;


	return *this;
}
