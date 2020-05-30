#ifndef __WNW_InputManagerClass_
#define __WNW_InputManagerClass_

#include "InterfaceManager.h"



class InputManager
{
protected:
public:
	//Constructors and Destructors//
	InputManager(unsigned int SCR_WIDTH = 1280, unsigned int SCR_HEIGHT = 720);
	InputManager(TileMap*, BuildingManager*, InterfaceManager*, ResourceManager*,unsigned int SCR_WIDTH = 1280, unsigned int SCR_HEIGHT = 720);
	InputManager(const InputManager& org);
	~InputManager();

	//Methods//
	void ReadEvent(sf::RenderWindow& window, sf::View& view);
	sf::Vector2i getmousePos();
	sf::Vector2f getmousePosf();
	//Overloads//
	InputManager& operator=(const InputManager& input);

protected:
	bool DeleteMode;
	InterfaceManager* IM1;
	BuildingManager* BManager;
	TileMap *Map;
	ResourceManager* RManager;
	sf::Vector2i mousePos;
	sf::Vector2f mousePosf;
	unsigned int SCR_WIDTH;
	unsigned int SCR_HEIGHT;

};

#endif