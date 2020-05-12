#ifndef __WNW_GameManagerClass_
#define __WNW_GameManagerClass_

#include "InputManager.h"

class GameManager
{
protected:
    void generateTrees();
public:
	//Constructors and Destructors//
	GameManager(unsigned int SCR_WIDTH = 1280, unsigned int SCR_HEIGHT = 720, unsigned int MapX = 10, unsigned int MapY = 20);
	GameManager(const GameManager& input);
	~GameManager();

	//Methods//
	void Initialise();
	void grabWindow(sf::RenderWindow &window);
	void RenderPass();

	//Overloads//
	GameManager& operator=(const GameManager& input);
	//Managers//
	BuildingManager BManager;
	InputManager InputManager;
	InterfaceManager IM1;
	TileMap Map;
	ResourceManager RManager;

	//Views//
	sf::View interfaceView;
	sf::View view;

	//Window//
	sf::RenderWindow* window;
	unsigned int SCR_WIDTH;
	unsigned int SCR_HEIGHT;
	sf::Sprite backgroundSprite;

	//Temp//
	bool timer;
protected:
	GameManager();

};

#endif