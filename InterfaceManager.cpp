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
        InterfaceElement Ie2Button1Pop1(0, 0 + interfaceHeight, (float)SCR_WIDTH/16, SCR_HEIGHT-2*interfaceHeight, color, false);
            InterfaceElement Ie2Button1Pop1Button1(0 + SCR_HEIGHT / 12 / 7, 0 + interfaceHeight + 16, (float)SCR_WIDTH / 16-20, SCR_HEIGHT/12 , sf::Color::White, true);
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
        InterfaceElement Ie2Button1Pop1Button1Panel(SCR_WIDTH/16, 0 + interfaceHeight + 16, (float)SCR_WIDTH / 3, SCR_HEIGHT / 12, color2, true);
        im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1Panel);
        im_.button1action_button1Status = true;
        //buttons
        InterfaceElement Ie2Button1Pop1Button1PanelButton1(SCR_WIDTH / 16+ SCR_WIDTH / 16 / 4, 0 + interfaceHeight + 20, (float)SCR_WIDTH / 21, (float)SCR_HEIGHT / 14, sf::Color::White, true);
        Ie2Button1Pop1Button1PanelButton1.setTexture(&im_.interfaceTextureManager.getTavernTexture());
        Ie2Button1Pop1Button1PanelButton1.setAction(cat1Building1);
        im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1PanelButton1);

        InterfaceElement Ie2Button1Pop1Button1PanelButton2(SCR_WIDTH / 16 + SCR_WIDTH / 16 / 4 + (float)SCR_HEIGHT / 14 + 16, 0 + interfaceHeight + 20, (float)SCR_WIDTH / 21, (float)SCR_HEIGHT / 14, sf::Color::White, true);
        Ie2Button1Pop1Button1PanelButton2.setTexture(&im_.interfaceTextureManager.getStablesTexture());
        Ie2Button1Pop1Button1PanelButton2.setAction(cat1Building2);
        im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1PanelButton2);

        InterfaceElement Ie2Button1Pop1Button1PanelButton3(SCR_WIDTH / 16 + SCR_WIDTH / 16 / 4 + 2*(float)SCR_HEIGHT / 14 + 2*16, 0 + interfaceHeight + 20, (float)SCR_WIDTH / 21, (float)SCR_HEIGHT / 14, sf::Color::White, true);
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
		*im_.bcounter = *im_.bcounter+1;
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
    if (!interfacePop2Vec.empty() && button1action_button1Status==true)
    {
        for (size_t i = 0; i < interfacePop2Vec.size(); i++)
        {
            interfacePop2Vec[i].draw(window);
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

InterfaceManager::~InterfaceManager()
{
}
