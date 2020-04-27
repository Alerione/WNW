#include "InterfaceManager.h"

float InterfaceManager::SCR_WIDTH = 0;
float InterfaceManager::SCR_HEIGHT = 0;
float InterfaceManager::interfaceHeight = 0;


void InterfaceManager::button1action(InterfaceManager& im_)
{
	sf::Color color;
	color.r = 40;
	color.g = 40;
	color.b = 40;
	color.a = 200;

	sf::Color color2;
	color2.r = 40;
	color2.g = 40;
	color2.b = 40;
	color2.a = 200;

	// Building menu 
	if (im_.button1actionStatus == false)
	{
		InterfaceElement Ie2Button1Pop1(0, 0 + interfaceHeight, (float)SCR_WIDTH / 16, SCR_HEIGHT - 2 * interfaceHeight, color, false);
		InterfaceElement Ie2Button1Pop1Button1(0 + SCR_HEIGHT / 12 / 7, 0 + interfaceHeight + 16, (float)SCR_WIDTH / 16 - 20, SCR_HEIGHT / 12, sf::Color::White, true);
		Ie2Button1Pop1Button1.setTexture(&im_.interfaceTextureManager.getMenuCat1Texture());
		Ie2Button1Pop1Button1.setAction(&InterfaceManager::button1action_button1);
		im_.interfacePopVec.push_back(Ie2Button1Pop1);
		im_.interfacePopVec.push_back(Ie2Button1Pop1Button1);
		im_.button1actionStatus = true;
	}
	else if (im_.button1actionStatus == true)
	{
		im_.interfacePopVec.clear();
		im_.interfacePop2Vec.clear();
		im_.button1actionStatus = false;
		im_.button1action_button1Status = false;

	}
}

void InterfaceManager::button1action_button1(InterfaceManager& im_)
{
	sf::Color color2;
	color2.r = 60;
	color2.g = 60;
	color2.b = 60;
	color2.a = 200;
	if (im_.button1action_button1Status == false)
	{
		InterfaceElement Ie2Button1Pop1Button1Panel(SCR_WIDTH / 16, 0 + interfaceHeight + 16, (float)SCR_WIDTH / 3, SCR_HEIGHT / 12, color2, true);
		im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1Panel);
		im_.button1action_button1Status = true;
		//buttons
		InterfaceElement Ie2Button1Pop1Button1PanelButton1(SCR_WIDTH / 16 + SCR_WIDTH / 16 / 4, 0 + interfaceHeight + 20, (float)SCR_WIDTH / 21, (float)SCR_HEIGHT / 14, sf::Color::White, true);
		Ie2Button1Pop1Button1PanelButton1.setTexture(&im_.interfaceTextureManager.getTavernTexture());
		Ie2Button1Pop1Button1PanelButton1.setAction(cat1Building1);
		im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1PanelButton1);

		InterfaceElement Ie2Button1Pop1Button1PanelButton2(SCR_WIDTH / 16 + SCR_WIDTH / 16 / 4 + (float)SCR_HEIGHT / 14 + 16, 0 + interfaceHeight + 20, (float)SCR_WIDTH / 21, (float)SCR_HEIGHT / 14, sf::Color::White, true);
		Ie2Button1Pop1Button1PanelButton2.setTexture(&im_.interfaceTextureManager.getStablesTexture());
		Ie2Button1Pop1Button1PanelButton2.setAction(cat1Building2);
		im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1PanelButton2);

		InterfaceElement Ie2Button1Pop1Button1PanelButton3(SCR_WIDTH / 16 + SCR_WIDTH / 16 / 4 + 2 * (float)SCR_HEIGHT / 14 + 2 * 16, 0 + interfaceHeight + 20, (float)SCR_WIDTH / 21, (float)SCR_HEIGHT / 14, sf::Color::White, true);
		Ie2Button1Pop1Button1PanelButton3.setTexture(&im_.interfaceTextureManager.getWellTexture());
		Ie2Button1Pop1Button1PanelButton3.setAction(cat1Building3);
		im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1PanelButton3);
	}
	else if (im_.button1action_button1Status == true)
	{
		im_.interfacePop2Vec.clear();
		im_.button1action_button1Status = false;
	}

}

void InterfaceManager::cat1Building1(InterfaceManager& im_)
{
	if (Building::CheckBusy() == false)
	{
		*im_.bcounter = *im_.bcounter + 1;
		im_.buildings->resize(*im_.bcounter);
		im_.buildings->back() = new TavernBuilding(im_.tileMap);
	}
}

void InterfaceManager::cat1Building2(InterfaceManager& im_)
{
	if (Building::CheckBusy() == false)
	{
		*im_.bcounter = *im_.bcounter + 1;
		im_.buildings->resize(*im_.bcounter);
		im_.buildings->back() = new StablesBuilding(im_.tileMap);
	}
}

void InterfaceManager::cat1Building3(InterfaceManager& im_)
{
	if (Building::CheckBusy() == false)
	{
		*im_.bcounter = *im_.bcounter + 1;
		im_.buildings->resize(*im_.bcounter);
		im_.buildings->back() = new WellBuilding(im_.tileMap);
	}
}

InterfaceManager::InterfaceManager()
{
	InterfaceManager::SCR_WIDTH = 1280;
	InterfaceManager::SCR_HEIGHT = 720;
	button1actionStatus = false;
	interfaceHeight = 0;
}

InterfaceManager::InterfaceManager(float scrw, float scrh)
	:Resources(nullptr)
{
	InterfaceManager::SCR_WIDTH = scrw;
	InterfaceManager::SCR_HEIGHT = scrh;
	button1actionStatus = false;
	interfaceHeight = 0;
}

void InterfaceManager::buildInterface(double interfaceHeight)
{
	this->interfaceHeight = (float)interfaceHeight;
	//Main interface elements
	sf::Color color;
	color.r = 40;
	color.g = 40;
	color.b = 40;
	color.a = 200;

	InterfaceElement Ie1(0, 0, (float)SCR_WIDTH, (float)interfaceHeight, color, false);
	InterfaceElement Ie2(0, (float)SCR_HEIGHT - (float)interfaceHeight, (float)SCR_WIDTH*(float)0.3, (float)interfaceHeight, color, false);
	InterfaceElement Ie3((float)SCR_WIDTH - (float)SCR_WIDTH * (float)0.15, (float)SCR_HEIGHT - (float)interfaceHeight, (float)SCR_WIDTH*(float)0.15, (float)interfaceHeight, color, false);

	//Left bottom menu interface elements - buttons
	sf::Color buttonColor;
	buttonColor.r = 255;
	buttonColor.g = 255;
	buttonColor.b = 255;
	buttonColor.a = 255;

	InterfaceElement Ie2Button1(10, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
	Ie2Button1.setTexture(&interfaceTextureManager.getInterfaceBuildButton());
	InterfaceElement Ie2Button2(10 + (float)SCR_WIDTH*(float)0.05 + 10, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
	Ie2Button2.setTexture(&interfaceTextureManager.getInterfaceDelButton());
	InterfaceElement Ie2Button3(10 + 2 * (float)SCR_WIDTH*(float)0.05 + 20, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
	Ie2Button3.setTexture(&interfaceTextureManager.getInterfaceCamButton());
	InterfaceElement Ie2Button4(10 + 3 * (float)SCR_WIDTH*(float)0.05 + 30, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
	Ie2Button4.setTexture(&interfaceTextureManager.getInterfaceStatsButton());
	InterfaceElement Ie2Button5(10 + 4 * (float)SCR_WIDTH*(float)0.05 + 40, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
	Ie2Button5.setTexture(&interfaceTextureManager.getInterfaceMenuButton());

	//Actions
	Ie2Button1.setAction(&InterfaceManager::button1action);

	//Pushing to vec
	interfaceVec.push_back(Ie1);

	interfaceVec.push_back(Ie2);
	interfaceVec.push_back(Ie2Button1);
	interfaceVec.push_back(Ie2Button2);
	interfaceVec.push_back(Ie2Button3);
	interfaceVec.push_back(Ie2Button4);
	interfaceVec.push_back(Ie2Button5);

	interfaceVec.push_back(Ie3);

	//------------ wood -----------
	if (!font.loadFromFile("slkscr.ttf")) {}

	InterfaceElement woodIcon(0, 0, 24, 24, sf::Color::White, 0);
	woodIcon.setTexture(&interfaceTextureManager.getIeWoodTexture());
	interfaceIcons.push_back(woodIcon);

	sf::Text woodValue;
	woodValue.setFont(font);
	woodValue.setString(std::to_string(Resources->Lumber));
	woodValue.setCharacterSize(14);
	woodValue.setFillColor(sf::Color::White);
	interfaceTexts.push_back(woodValue);

	//---------------------------

	InterfaceElement clayIcon(0, 0, 24, 24, sf::Color::White, 0);
	clayIcon.setTexture(&interfaceTextureManager.getIeClayTexture());
	interfaceIcons.push_back(clayIcon);

	sf::Text clayValue;
	clayValue.setFont(font);
	clayValue.setString(std::to_string(Resources->Clay));
	clayValue.setCharacterSize(14);
	clayValue.setFillColor(sf::Color::White);
	interfaceTexts.push_back(clayValue);

	//---------------------------

	InterfaceElement marbleIcon(0, 0, 24, 24, sf::Color::White, 0);
	marbleIcon.setTexture(&interfaceTextureManager.getIeMarbleTexture());
	interfaceIcons.push_back(marbleIcon);

	sf::Text marbleValue;
	marbleValue.setFont(font);
	marbleValue.setString(std::to_string(Resources->Marble));
	marbleValue.setCharacterSize(14);
	marbleValue.setFillColor(sf::Color::White);
	interfaceTexts.push_back(marbleValue);

	//---------------------------

	InterfaceElement planksIcon(0, 0, 24, 24, sf::Color::White, 0);
	planksIcon.setTexture(&interfaceTextureManager.getIePlanksTexture());
	interfaceIcons.push_back(planksIcon);

	sf::Text planksValue;
	planksValue.setFont(font);
	planksValue.setString(std::to_string(Resources->Planks));
	planksValue.setCharacterSize(14);
	planksValue.setFillColor(sf::Color::White);
	interfaceTexts.push_back(planksValue);

	//---------------------------

	InterfaceElement bricksIcon(0, 0, 24, 24, sf::Color::White, 0);
	bricksIcon.setTexture(&interfaceTextureManager.getIeBricksTexture());
	interfaceIcons.push_back(bricksIcon);

	sf::Text bricksValue;
	bricksValue.setFont(font);
	bricksValue.setString(std::to_string(Resources->Bricks));
	bricksValue.setCharacterSize(14);
	bricksValue.setFillColor(sf::Color::White);
	interfaceTexts.push_back(bricksValue);

	//---------------------------

	InterfaceElement polishedMarbleIcon(0, 0, 24, 24, sf::Color::White, 0);
	polishedMarbleIcon.setTexture(&interfaceTextureManager.getIePolishedMarbleTexture());
	interfaceIcons.push_back(polishedMarbleIcon);

	sf::Text polishedMarbleValue;
	polishedMarbleValue.setFont(font);
	polishedMarbleValue.setString(std::to_string(Resources->MarbleBlocks));
	polishedMarbleValue.setCharacterSize(14);
	polishedMarbleValue.setFillColor(sf::Color::White);
	interfaceTexts.push_back(polishedMarbleValue);

	//---------------------------

	InterfaceElement moneyIcon(10, 10, 24, 24, sf::Color::White, 0);
	moneyIcon.setTexture(&interfaceTextureManager.getIeGoldTexture());
	interfaceIcons.push_back(moneyIcon);

	sf::Text moneyValue;
	moneyValue.setFont(font);
	moneyValue.setString(std::to_string(Resources->Ducats));
	moneyValue.setCharacterSize(14);
	moneyValue.setFillColor(sf::Color::White);
	interfaceTexts.push_back(moneyValue);
	//===============================================================================
	//================================RESOURCES PREV=================================
	//===============================================================================

	sf::Text woodPrev;
	woodPrev.setFont(font);
	if (Resources->Lumber > Resources->Prev_Lumber)
	{
		woodPrev.setString("(+" + std::to_string(Resources->Lumber - Resources->Prev_Lumber) + ")");
		woodPrev.setFillColor(sf::Color::Green);
	}
	else if (Resources->Lumber == Resources->Prev_Lumber)
	{
		woodPrev.setString("(+0)");
		woodPrev.setFillColor(sf::Color::Color(255, 140, 0));
	}
	else
	{
		woodPrev.setString("(" + std::to_string(Resources->Lumber - Resources->Prev_Lumber) + ")");
		woodPrev.setFillColor(sf::Color::Red);
	}
	woodPrev.setCharacterSize(14);
	interfacePrev.push_back(woodPrev);
	//--------------------------------------------------------------
	sf::Text clayPrev;
	clayPrev.setFont(font);
	if (Resources->Clay > Resources->Prev_Clay)
	{
		clayPrev.setString("(+" + std::to_string(Resources->Clay - Resources->Prev_Clay) + ")");
		clayPrev.setFillColor(sf::Color::Green);
	}
	else if (Resources->Clay == Resources->Prev_Clay)
	{
		clayPrev.setString("(+0)");
		clayPrev.setFillColor(sf::Color::Color(255, 140, 0));
	}
	else
	{
		clayPrev.setString("(" + std::to_string(Resources->Clay - Resources->Prev_Clay) + ")");
		clayPrev.setFillColor(sf::Color::Red);
	}
	clayPrev.setCharacterSize(14);
	interfacePrev.push_back(clayPrev);
	//--------------------------------------------------------------
	sf::Text marblePrev;
	marblePrev.setFont(font);
	if (Resources->Marble > Resources->Prev_Marble)
	{
		marblePrev.setString("(+" + std::to_string(Resources->Marble - Resources->Prev_Marble) + ")");
		marblePrev.setFillColor(sf::Color::Green);
	}
	else if (Resources->Marble == Resources->Prev_Marble)
	{
		marblePrev.setString("(+0)");
		marblePrev.setFillColor(sf::Color::Color(255, 140, 0));
	}
	else
	{
		marblePrev.setString("(" + std::to_string(Resources->Marble - Resources->Prev_Marble) + ")");
		marblePrev.setFillColor(sf::Color::Red);
	}
	marblePrev.setCharacterSize(14);
	interfacePrev.push_back(marblePrev);
	//--------------------------------------------------------------
	sf::Text plankPrev;
	plankPrev.setFont(font);
	if (Resources->Planks > Resources->Prev_Planks)
	{
		plankPrev.setString("(+" + std::to_string(Resources->Planks - Resources->Prev_Planks) + ")");
		plankPrev.setFillColor(sf::Color::Green);
	}
	else if (Resources->Planks == Resources->Prev_Planks)
	{
		plankPrev.setString("(+0)");
		plankPrev.setFillColor(sf::Color::Color(255, 140, 0));
	}
	else
	{
		plankPrev.setString("(" + std::to_string(Resources->Planks - Resources->Prev_Planks) + ")");
		plankPrev.setFillColor(sf::Color::Red);
	}
	plankPrev.setCharacterSize(14);
	interfacePrev.push_back(plankPrev);
	//--------------------------------------------------------------
	sf::Text bricksPrev;
	bricksPrev.setFont(font);
	if (Resources->Prev_Bricks > Resources->Prev_Bricks)
	{
		bricksPrev.setString("(+" + std::to_string(Resources->Bricks - Resources->Prev_Bricks) + ")");
		bricksPrev.setFillColor(sf::Color::Green);
	}
	else if (Resources->Prev_Bricks == Resources->Prev_Bricks)
	{
		bricksPrev.setString("(+0)");
		bricksPrev.setFillColor(sf::Color::Color(255, 140, 0));
	}
	else
	{
		bricksPrev.setString("(" + std::to_string(Resources->Bricks - Resources->Prev_Bricks) + ")");
		bricksPrev.setFillColor(sf::Color::Red);
	}
	bricksPrev.setCharacterSize(14);
	bricksPrev.setFillColor(sf::Color::Green);
	interfacePrev.push_back(bricksPrev);
	//--------------------------------------------------------------
	sf::Text polMarPrev;
	polMarPrev.setFont(font);
	if (Resources->MarbleBlocks > Resources->Prev_MarbleBlocks)
	{
		polMarPrev.setString("(+" + std::to_string(Resources->MarbleBlocks - Resources->Prev_MarbleBlocks) + ")");
		polMarPrev.setFillColor(sf::Color::Green);
	}
	else if (Resources->MarbleBlocks == Resources->Prev_MarbleBlocks)
	{
		polMarPrev.setString("(+0)");
		polMarPrev.setFillColor(sf::Color::Color(255, 140, 0));
	}
	else
	{
		polMarPrev.setString("(" + std::to_string(Resources->MarbleBlocks - Resources->Prev_MarbleBlocks) + ")");
		polMarPrev.setFillColor(sf::Color::Red);
	}
	polMarPrev.setCharacterSize(14);
	interfacePrev.push_back(polMarPrev);
	//--------------------------------------------------------------
	sf::Text goldPrev;
	goldPrev.setFont(font);
	if (Resources->Ducats > Resources->Prev_Ducats)
	{
		goldPrev.setString("(+" + std::to_string(Resources->Ducats - Resources->Prev_Ducats) + ")");
		goldPrev.setFillColor(sf::Color::Green);
	}
	else if (Resources->Ducats == Resources->Prev_Ducats)
	{
		goldPrev.setString("(+0)");
		goldPrev.setFillColor(sf::Color::Color(255, 140, 0));
	}
	else
	{
		goldPrev.setString("(" + std::to_string(Resources->Ducats - Resources->Prev_Ducats) + ")");
		goldPrev.setFillColor(sf::Color::Red);
	}
	goldPrev.setCharacterSize(14);
	interfacePrev.push_back(goldPrev);
}

void InterfaceManager::drawInterface(sf::RenderWindow& window)
{
	for (size_t i = 0; i < interfaceVec.size(); i++)
	{
		interfaceVec[i].draw(window);
	}
	if (!interfacePopVec.empty())
	{
		for (size_t i = 0; i < interfacePopVec.size(); i++)
		{
			interfacePopVec[i].draw(window);
		}
	}
	if (!interfacePop2Vec.empty() && button1action_button1Status == true)
	{
		for (size_t i = 0; i < interfacePop2Vec.size(); i++)
		{
			interfacePop2Vec[i].draw(window);
		}
	}
	if (!interfaceIcons.empty())
	{
		for (size_t i = 0; i < interfaceIcons.size(); i++)
		{
			interfaceIcons[i]._shape.setPosition((float)i * 120 + 50, 4);
			interfaceIcons[i].draw(window);
		}
	}
	if (!interfaceTexts.empty())
	{
		for (size_t i = 0; i < interfaceTexts.size(); i++)
		{
			interfaceTexts[i].setPosition((float)i * 120 + 80, 10);
			window.draw(interfaceTexts[i]);
		}
	}
	if (!interfacePrev.empty())
	{
		for (size_t i = 0; i < interfacePrev.size(); i++)
		{
			interfacePrev[i].setPosition((float)i * 120 + 120, 10);
			window.draw(interfacePrev[i]);
		}
	}
}

void InterfaceManager::updateInterace(sf::Vector2f mouse, std::vector <Building*>& buildings_, TileMap& tm_, int& buildingcoutner)
{
	buildings = &buildings_;
	tileMap = &tm_;
	bcounter = &buildingcoutner;
	for (size_t i = 0; i < interfaceVec.size(); i++)
	{
		interfaceVec[i].update(mouse);
	}
	if (!interfacePopVec.empty())
	{
		for (size_t i = 0; i < interfacePopVec.size(); i++)
		{
			interfacePopVec[i].update(mouse);
		}
	}
	if (!interfacePop2Vec.empty() && button1action_button1Status == true)
	{
		for (size_t i = 0; i < interfacePop2Vec.size(); i++)
		{
			interfacePop2Vec[i].update(mouse);
		}
	}
}

void InterfaceManager::clickedUpdateInterface(sf::Vector2f mouse, InterfaceManager& im)
{
	for (size_t i = 0; i < interfaceVec.size(); i++)                                // caly czas widoczny
	{
		interfaceVec[i].clickedUpdate(mouse, im);
	}
	if (!interfacePopVec.empty())
	{
		for (size_t i = 0; i < interfacePopVec.size(); i++)                          // po 1 kliknieciu
		{
			interfacePopVec[i].clickedUpdate(mouse, im);
		}
	}
	if (!interfacePop2Vec.empty() && button1action_button1Status == true)           // po 2 kliknieciu
	{
		for (size_t i = 0; i < interfacePop2Vec.size(); i++)
		{
			interfacePop2Vec[i].clickedUpdate(mouse, im);
		}
	}
}

void InterfaceManager::getResources(ResourceList * list)
{
	Resources = list;
}

void InterfaceManager::updateResources()
{
	interfaceTexts[0].setString(std::to_string(Resources->Lumber));
	interfaceTexts[1].setString(std::to_string(Resources->Clay));
	interfaceTexts[2].setString(std::to_string(Resources->Marble));
	interfaceTexts[3].setString(std::to_string(Resources->Planks));
	interfaceTexts[4].setString(std::to_string(Resources->Bricks));
	interfaceTexts[5].setString(std::to_string(Resources->MarbleBlocks));
	interfaceTexts[6].setString(std::to_string(Resources->Ducats));

	if (Resources->Lumber > Resources->Prev_Lumber)
	{
		interfacePrev[0].setString("(+" + std::to_string(Resources->Lumber - Resources->Prev_Lumber) + ")");
		interfacePrev[0].setFillColor(sf::Color::Green);
	}
	else if (Resources->Lumber == Resources->Prev_Lumber)
	{
		interfacePrev[0].setString("(+0)");
		interfacePrev[0].setFillColor(sf::Color::Color(255, 140, 0));
	}
	else
	{
		interfacePrev[0].setString("(" + std::to_string(Resources->Lumber - Resources->Prev_Lumber) + ")");
		interfacePrev[0].setFillColor(sf::Color::Red);
	}
	if (Resources->Clay > Resources->Prev_Clay)
	{
		interfacePrev[1].setString("(+" + std::to_string(Resources->Clay - Resources->Prev_Clay) + ")");
		interfacePrev[1].setFillColor(sf::Color::Green);
	}
	else if (Resources->Clay == Resources->Prev_Clay)
	{
		interfacePrev[1].setString("(+0)");
		interfacePrev[1].setFillColor(sf::Color::Color(255, 140, 0));
	}
	else
	{
		interfacePrev[1].setString("(" + std::to_string(Resources->Clay - Resources->Prev_Clay) + ")");
		interfacePrev[1].setFillColor(sf::Color::Red);
	}
	if (Resources->Marble > Resources->Prev_Marble)
	{
		interfacePrev[2].setString("(+" + std::to_string(Resources->Marble - Resources->Prev_Marble) + ")");
		interfacePrev[2].setFillColor(sf::Color::Green);
	}
	else if (Resources->Marble == Resources->Prev_Marble)
	{
		interfacePrev[2].setString("(+0)");
		interfacePrev[2].setFillColor(sf::Color::Color(255, 140, 0));
	}
	else
	{
		interfacePrev[2].setString("(" + std::to_string(Resources->Marble - Resources->Prev_Marble) + ")");
		interfacePrev[2].setFillColor(sf::Color::Red);
	}
	if (Resources->Planks > Resources->Prev_Planks)
	{
		interfacePrev[3].setString("(+" + std::to_string(Resources->Planks - Resources->Prev_Planks) + ")");
		interfacePrev[3].setFillColor(sf::Color::Green);
	}
	else if (Resources->Planks == Resources->Prev_Planks)
	{
		interfacePrev[3].setString("(+0)");
		interfacePrev[3].setFillColor(sf::Color::Color(255, 140, 0));
	}
	else
	{
		interfacePrev[3].setString("(" + std::to_string(Resources->Planks - Resources->Prev_Planks) + ")");
		interfacePrev[3].setFillColor(sf::Color::Red);
	}
	if (Resources->Prev_Bricks > Resources->Prev_Bricks)
	{
		interfacePrev[4].setString("(+" + std::to_string(Resources->Bricks - Resources->Prev_Bricks) + ")");
		interfacePrev[4].setFillColor(sf::Color::Green);
	}
	else if (Resources->Prev_Bricks == Resources->Prev_Bricks)
	{
		interfacePrev[4].setString("(+0)");
		interfacePrev[4].setFillColor(sf::Color::Color(255, 140, 0));
	}
	else
	{
		interfacePrev[4].setString("(" + std::to_string(Resources->Bricks - Resources->Prev_Bricks) + ")");
		interfacePrev[4].setFillColor(sf::Color::Red);
	}
	if (Resources->MarbleBlocks > Resources->Prev_MarbleBlocks)
	{
		interfacePrev[5].setString("(+" + std::to_string(Resources->MarbleBlocks - Resources->Prev_MarbleBlocks) + ")");
		interfacePrev[5].setFillColor(sf::Color::Green);
	}
	else if (Resources->MarbleBlocks == Resources->Prev_MarbleBlocks)
	{
		interfacePrev[5].setString("(+0)");
		interfacePrev[5].setFillColor(sf::Color::Color(255, 140, 0));
	}
	else
	{
		interfacePrev[5].setString("(" + std::to_string(Resources->MarbleBlocks - Resources->Prev_MarbleBlocks) + ")");
		interfacePrev[5].setFillColor(sf::Color::Red);
	}
	if (Resources->Ducats > Resources->Prev_Ducats)
	{
		interfacePrev[6].setString("(+" + std::to_string(Resources->Ducats - Resources->Prev_Ducats) + ")");
		interfacePrev[6].setFillColor(sf::Color::Green);
	}
	else if (Resources->Ducats == Resources->Prev_Ducats)
	{
		interfacePrev[6].setString("(+0)");
		interfacePrev[6].setFillColor(sf::Color::Color(255, 140, 0));
	}
	else
	{
		interfacePrev[6].setString("(" + std::to_string(Resources->Ducats - Resources->Prev_Ducats) + ")");
		interfacePrev[6].setFillColor(sf::Color::Red);
	}

}

void InterfaceManager::setResourceInterfaceValue(int index, std::string& value)
{
	interfaceTexts.at(index).setString(value);
}

InterfaceManager::~InterfaceManager()
{
}
