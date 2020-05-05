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
        InterfaceElement Ie2Button1Pop1(0, 60, (float)SCR_WIDTH / 16, SCR_HEIGHT - 1 * interfaceHeight - 60, sf::Color::White, false);
        sf::IntRect d(0, 0, float(SCR_WIDTH) / 16, (float)interfaceHeight * 5);
        Ie2Button1Pop1._shape.setTextureRect(d);
        Ie2Button1Pop1.setTexture(&im_.tileMap->getTexMngr().getIeBg2Texture());

        InterfaceElement Ie2Button1Pop1Button1(0 + SCR_HEIGHT / 12 / 7, 0 + interfaceHeight + 16, (float)SCR_WIDTH / 16 - 20, SCR_HEIGHT / 12, sf::Color::White, true);
        Ie2Button1Pop1Button1.setTexture(&im_.tileMap->getTexMngr().getMenuCat1Texture());
        Ie2Button1Pop1Button1.setAction(&InterfaceManager::button1action_button1);

        InterfaceElement Ie2Button1Pop1Button2(0 + SCR_HEIGHT / 12 / 7, 0 + 3 * interfaceHeight, (float)SCR_WIDTH / 16 - 20, SCR_HEIGHT / 12, sf::Color::White, true);
        Ie2Button1Pop1Button2.setTexture(&im_.tileMap->getTexMngr().getMenuCat2Texture());
        Ie2Button1Pop1Button2.setAction(&InterfaceManager::button1action_button2);

        im_.interfacePopVec.push_back(Ie2Button1Pop1);
        im_.interfacePopVec.push_back(Ie2Button1Pop1Button1);
        im_.interfacePopVec.push_back(Ie2Button1Pop1Button2);
        im_.button1actionStatus = true;
    }
    else if (im_.button1actionStatus == true)
    {
        im_.interfacePopVec.clear();
        im_.interfacePop2Vec.clear();
        im_.button1actionStatus = false;
        im_.button1action_button1Status = false;
        im_.button1action_button2Status = false;

    }
}

void InterfaceManager::button1action_button1(InterfaceManager& im_)
{
    sf::Color color2;
    color2.r = 60;
    color2.g = 60;
    color2.b = 60;
    color2.a = 200;
    if (im_.button1action_button1Status == false && im_.button1action_button2Status == false)
    {
        InterfaceElement Ie2Button1Pop1Button1Panel(SCR_WIDTH / 16, 0 + interfaceHeight + 16, (float)SCR_WIDTH / 3, SCR_HEIGHT / 12, sf::Color::White, true);
        sf::IntRect d(0, 0, float(SCR_WIDTH) / 4, (float)interfaceHeight*3);
        Ie2Button1Pop1Button1Panel._shape.setTextureRect(d);
        Ie2Button1Pop1Button1Panel.setTexture(&im_.tileMap->getTexMngr().getIeBg3Texture());

        im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1Panel);
        im_.button1action_button1Status = true;
        //buttons
        InterfaceElement Ie2Button1Pop1Button1PanelButton1(SCR_WIDTH / 16 + SCR_WIDTH / 16 / 4, 0 + interfaceHeight + 20, (float)SCR_WIDTH / 21, (float)SCR_HEIGHT / 14, sf::Color::White, true);
        Ie2Button1Pop1Button1PanelButton1.setTexture(&im_.tileMap->getTexMngr().getTavernTexture());
        Ie2Button1Pop1Button1PanelButton1.setAction(cat1Building1);
        im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1PanelButton1);

        InterfaceElement Ie2Button1Pop1Button1PanelButton2(SCR_WIDTH / 16 + SCR_WIDTH / 16 / 4 + (float)SCR_HEIGHT / 14 + 16, 0 + interfaceHeight + 20, (float)SCR_WIDTH / 21, (float)SCR_HEIGHT / 14, sf::Color::White, true);
        Ie2Button1Pop1Button1PanelButton2.setTexture(&im_.tileMap->getTexMngr().getStablesTexture());
        Ie2Button1Pop1Button1PanelButton2.setAction(cat1Building2);
        im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1PanelButton2);

        InterfaceElement Ie2Button1Pop1Button1PanelButton3(SCR_WIDTH / 16 + SCR_WIDTH / 16 / 4 + 2 * (float)SCR_HEIGHT / 14 + 2 * 16, 0 + interfaceHeight + 20, (float)SCR_WIDTH / 21, (float)SCR_HEIGHT / 14, sf::Color::White, true);
        Ie2Button1Pop1Button1PanelButton3.setTexture(&im_.tileMap->getTexMngr().getWellTexture());
        Ie2Button1Pop1Button1PanelButton3.setAction(cat1Building3);
        im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1PanelButton3);

        InterfaceElement Ie2Button1Pop1Button1PanelButton4(SCR_WIDTH / 16 + SCR_WIDTH / 16 / 4 + 2 * (float)SCR_HEIGHT / 14 + 6 * 16, 0 + interfaceHeight + 20, (float)SCR_WIDTH / 21, (float)SCR_HEIGHT / 14, sf::Color::White, true);
        Ie2Button1Pop1Button1PanelButton4.setTexture(&im_.tileMap->getTexMngr().getBarracksTexture());
        Ie2Button1Pop1Button1PanelButton4.setAction(cat1Building4);
        im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1PanelButton4);
    }
    else if (im_.button1action_button1Status == true)
    {
        im_.interfacePop2Vec.clear();
        im_.button1action_button1Status = false;
        im_.button1action_button2Status = false;
    }
    else if (im_.button1action_button2Status == true)
    {
        im_.interfacePop2Vec.clear();
        im_.button1action_button2Status = false;
    }

}

void InterfaceManager::button1action_button2(InterfaceManager& im_)
{
    sf::Color color2;
    color2.r = 60;
    color2.g = 60;
    color2.b = 60;
    color2.a = 200;
    if (im_.button1action_button2Status == false && im_.button1action_button1Status == false)
    { 
        InterfaceElement Ie2Button1Pop1Button1Panel(SCR_WIDTH / 16, 0 + 3*interfaceHeight + 8, (float)SCR_WIDTH / 3, SCR_HEIGHT / 12, sf::Color::White, true);
        sf::IntRect d(0, 0, float(SCR_WIDTH) / 4, (float)interfaceHeight * 3);
        Ie2Button1Pop1Button1Panel._shape.setTextureRect(d);
        Ie2Button1Pop1Button1Panel.setTexture(&im_.tileMap->getTexMngr().getIeBg3Texture());
        im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1Panel);
        im_.button1action_button2Status = true;
        ////buttons
        InterfaceElement Ie2Button1Pop1Button1PanelButton1(SCR_WIDTH / 16 + SCR_WIDTH / 16 / 4, 0 + 3*interfaceHeight + 8, (float)SCR_WIDTH / 21, (float)SCR_HEIGHT / 14, sf::Color::White, true);
        Ie2Button1Pop1Button1PanelButton1.setTexture(&im_.tileMap->getTexMngr().getSawmillTexture());
        Ie2Button1Pop1Button1PanelButton1.setAction(cat2Building1);
        im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1PanelButton1);

        InterfaceElement Ie2Button1Pop1Button1PanelButton2(SCR_WIDTH / 16 + SCR_WIDTH / 16 / 4 + (float)SCR_HEIGHT / 14 + 16, 0 + 3*interfaceHeight + 8, (float)SCR_WIDTH / 21, (float)SCR_HEIGHT / 14, sf::Color::White, true);
        Ie2Button1Pop1Button1PanelButton2.setTexture(&im_.tileMap->getTexMngr().getQuarryTexture());
        Ie2Button1Pop1Button1PanelButton2.setAction(cat2Building1);
        im_.interfacePop2Vec.push_back(Ie2Button1Pop1Button1PanelButton2);

    }
    else if (im_.button1action_button2Status == true)
    {
        im_.interfacePop2Vec.clear();
        im_.button1action_button1Status = false;
        im_.button1action_button2Status = false;
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

void InterfaceManager::cat1Building4(InterfaceManager& im_)
{
    if (Building::CheckBusy() == false)
    {
        *im_.bcounter = *im_.bcounter + 1;
        im_.buildings->resize(*im_.bcounter);
        im_.buildings->back() = new BarracksBuilding(im_.tileMap);
    }
}

void InterfaceManager::cat2Building1(InterfaceManager& im_)
{
    if (Building::CheckBusy() == false)
    {
        *im_.bcounter = *im_.bcounter + 1;
        im_.buildings->resize(*im_.bcounter);
        im_.buildings->back() = new SawmillBuilding(im_.tileMap);
    }
}

void InterfaceManager::cat2Building2(InterfaceManager& im_)
{
    if (Building::CheckBusy() == false)
    {
        *im_.bcounter = *im_.bcounter + 1;
        im_.buildings->resize(*im_.bcounter);
        im_.buildings->back() = new QuarryBuilding(im_.tileMap);
    }
}

void InterfaceManager::infoBarAction(InterfaceManager& im_, Building* building)
{
    if (building!=nullptr && im_.infoBarShowed==false)
    {
		im_.InfobarGrab = building;

        im_.infoBarShowed = true;
        InterfaceElement InfoBarPanel((float)SCR_WIDTH - (float)SCR_WIDTH / 10, 60, (float)SCR_WIDTH / 10, (float)SCR_HEIGHT - interfaceHeight - 60, sf::Color::White, false);
        sf::IntRect d(0, 0, float(SCR_WIDTH) / 8, (float)interfaceHeight * 5);
        InfoBarPanel._shape.setTextureRect(d);
        InfoBarPanel.setTexture(&im_.tileMap->getTexMngr().getIeBg3Texture());
        im_.infoBar.push_back(InfoBarPanel);

        sf::Text happ;
        happ.setFont(im_.font);
		happ.setCharacterSize(14);
        happ.setFillColor(sf::Color::White);
        happ.setPosition(sf::Vector2f((float)SCR_WIDTH - (float)SCR_WIDTH / 10 + 16, 1.5*(float)interfaceHeight));
        happ.setString("Happiness: " + std::to_string(building->getDataGame().Happiness));
        im_.infoBarTexts.push_back(happ);

        sf::Text hp;
        hp.setFont(im_.font);
		hp.setCharacterSize(14);
        hp.setFillColor(sf::Color::White);
        hp.setPosition(sf::Vector2f((float)SCR_WIDTH - (float)SCR_WIDTH / 10 + 16, 1.5*(float)interfaceHeight + 32));
        hp.setString("Health: " + std::to_string(building->getDataGame().Health));
        im_.infoBarTexts.push_back(hp);

        sf::Text po;
        po.setFont(im_.font);
		po.setCharacterSize(14);
        po.setFillColor(sf::Color::White);
        po.setPosition(sf::Vector2f((float)SCR_WIDTH - (float)SCR_WIDTH / 10 + 16, 1.5*(float)interfaceHeight + 64));
        po.setString("Public Order: " + std::to_string(building->getDataGame().PublicOrder));
        im_.infoBarTexts.push_back(po);

        sf::Text wa;
        wa.setFont(im_.font);
		wa.setCharacterSize(14);
        wa.setFillColor(sf::Color::White);
        wa.setPosition(sf::Vector2f((float)SCR_WIDTH - (float)SCR_WIDTH / 10 + 16, 1.5*(float)interfaceHeight + 96 ));
		if (building->getDataGame().WaterAccess)
		{
			wa.setString("Water Available");
		}
		else
		{
			wa.setString("Water Unavailable");
		}
        im_.infoBarTexts.push_back(wa);
    }
	else if (building != nullptr && im_.infoBarShowed == true)
	{
		im_.InfobarGrab = building;
		im_.infoBarTexts[0].setString("Happiness: " + std::to_string(im_.InfobarGrab->getDataGame().Happiness));
		im_.infoBarTexts[1].setString("Health: " + std::to_string(im_.InfobarGrab->getDataGame().Health));
		im_.infoBarTexts[2].setString("Public Order: " + std::to_string(im_.InfobarGrab->getDataGame().PublicOrder));
		if (im_.InfobarGrab->getDataGame().WaterAccess)
		{
			im_.infoBarTexts[3].setString("Water Available");
		}
		else
		{
			im_.infoBarTexts[3].setString("Water Unavailable");
		}

	}
    else
    {
		im_.InfobarGrab = nullptr;
        im_.infoBar.clear();
        im_.infoBarTexts.clear();
        im_.infoBarShowed = false;
    }

}

InterfaceManager::InterfaceManager()
{
    InterfaceManager::SCR_WIDTH = 1280;
    InterfaceManager::SCR_HEIGHT = 720;
    button1actionStatus = false;
    interfaceHeight = 0;
    infoBarShowed = false;
}

InterfaceManager::InterfaceManager(float scrw, float scrh)
    :Resources(nullptr)
{
    InterfaceManager::SCR_WIDTH = scrw;
    InterfaceManager::SCR_HEIGHT = scrh;
    button1actionStatus = false;
    infoBarShowed = false;
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

    InterfaceElement Ie1(0, 0, (float)SCR_WIDTH, (float)60, sf::Color::White, false);
    sf::IntRect a(0, 0, float(SCR_WIDTH) * 5, (float)interfaceHeight * 5);
    Ie1._shape.setTextureRect(a);
    Ie1.setTexture(&tileMap->getTexMngr().getIeBgTexture());

    InterfaceElement Ie2(0, (float)SCR_HEIGHT - (float)interfaceHeight, (float)SCR_WIDTH*(float)0.3, (float)interfaceHeight, sf::Color::White, false);
    sf::IntRect b(0, 0, float(SCR_WIDTH)*2, (float)interfaceHeight*5);
    Ie2._shape.setTextureRect(b);
    Ie2.setTexture(&tileMap->getTexMngr().getIeBgTexture());

    InterfaceElement Ie3((float)SCR_WIDTH - (float)SCR_WIDTH * (float)0.15, (float)SCR_HEIGHT - (float)interfaceHeight, (float)SCR_WIDTH*(float)0.15, (float)interfaceHeight, sf::Color::White, false);
    sf::IntRect c(0, 0, float(SCR_WIDTH) * 1, (float)interfaceHeight * 5);
    Ie3._shape.setTextureRect(c);
    Ie3.setTexture(&tileMap->getTexMngr().getIeBgTexture());

    //Left bottom menu interface elements - buttons
    sf::Color buttonColor;
    buttonColor.r = 255;
    buttonColor.g = 255;
    buttonColor.b = 255;
    buttonColor.a = 255;

    InterfaceElement Ie2Button1(10, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
    Ie2Button1.setTexture(&tileMap->getTexMngr().getInterfaceBuildButton());
    InterfaceElement Ie2Button2(10 + (float)SCR_WIDTH*(float)0.05 + 10, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
    Ie2Button2.setTexture(&tileMap->getTexMngr().getInterfaceDelButton());
    InterfaceElement Ie2Button3(10 + 2 * (float)SCR_WIDTH*(float)0.05 + 20, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
    Ie2Button3.setTexture(&tileMap->getTexMngr().getInterfaceCamButton());
    InterfaceElement Ie2Button4(10 + 3 * (float)SCR_WIDTH*(float)0.05 + 30, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
    Ie2Button4.setTexture(&tileMap->getTexMngr().getInterfaceStatsButton());
    InterfaceElement Ie2Button5(10 + 4 * (float)SCR_WIDTH*(float)0.05 + 40, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
    Ie2Button5.setTexture(&tileMap->getTexMngr().getInterfaceMenuButton());



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
    woodIcon.setTexture(&tileMap->getTexMngr().getIeWoodTexture());
    interfaceIcons.push_back(woodIcon);

    sf::Text woodValue;
    woodValue.setFont(font);
    woodValue.setString(std::to_string(Resources->Lumber));
    woodValue.setCharacterSize(14);
    woodValue.setFillColor(sf::Color::White);
    interfaceTexts.push_back(woodValue);

    //---------------------------

    InterfaceElement clayIcon(0, 0, 24, 24, sf::Color::White, 0);
    clayIcon.setTexture(&tileMap->getTexMngr().getIeClayTexture());
    interfaceIcons.push_back(clayIcon);

    sf::Text clayValue;
    clayValue.setFont(font);
    clayValue.setString(std::to_string(Resources->Clay));
    clayValue.setCharacterSize(14);
    clayValue.setFillColor(sf::Color::White);
    interfaceTexts.push_back(clayValue);

    //---------------------------

    InterfaceElement marbleIcon(0, 0, 24, 24, sf::Color::White, 0);
    marbleIcon.setTexture(&tileMap->getTexMngr().getIeMarbleTexture());
    interfaceIcons.push_back(marbleIcon);

    sf::Text marbleValue;
    marbleValue.setFont(font);
    marbleValue.setString(std::to_string(Resources->Marble));
    marbleValue.setCharacterSize(14);
    marbleValue.setFillColor(sf::Color::White);
    interfaceTexts.push_back(marbleValue);

    //---------------------------

    InterfaceElement planksIcon(0, 0, 24, 24, sf::Color::White, 0);
    planksIcon.setTexture(&tileMap->getTexMngr().getIePlanksTexture());
    interfaceIcons.push_back(planksIcon);

    sf::Text planksValue;
    planksValue.setFont(font);
    planksValue.setString(std::to_string(Resources->Planks));
    planksValue.setCharacterSize(14);
    planksValue.setFillColor(sf::Color::White);
    interfaceTexts.push_back(planksValue);

    //---------------------------

    InterfaceElement bricksIcon(0, 0, 24, 24, sf::Color::White, 0);
    bricksIcon.setTexture(&tileMap->getTexMngr().getIeBricksTexture());
    interfaceIcons.push_back(bricksIcon);

    sf::Text bricksValue;
    bricksValue.setFont(font);
    bricksValue.setString(std::to_string(Resources->Bricks));
    bricksValue.setCharacterSize(14);
    bricksValue.setFillColor(sf::Color::White);
    interfaceTexts.push_back(bricksValue);

    //---------------------------

    InterfaceElement polishedMarbleIcon(0, 0, 24, 24, sf::Color::White, 0);
    polishedMarbleIcon.setTexture(&tileMap->getTexMngr().getIePolishedMarbleTexture());
    interfaceIcons.push_back(polishedMarbleIcon);

    sf::Text polishedMarbleValue;
    polishedMarbleValue.setFont(font);
    polishedMarbleValue.setString(std::to_string(Resources->MarbleBlocks));
    polishedMarbleValue.setCharacterSize(14);
    polishedMarbleValue.setFillColor(sf::Color::White);
    interfaceTexts.push_back(polishedMarbleValue);

    //---------------------------

    InterfaceElement moneyIcon(10, 10, 24, 24, sf::Color::White, 0);
    moneyIcon.setTexture(&tileMap->getTexMngr().getIeGoldTexture());
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
    if (!interfacePop2Vec.empty() && (button1action_button1Status == true || button1action_button2Status == true))
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
            interfaceIcons[i]._shape.setPosition((float)((i - i % 2) / 2) * 160 + 25, 2 + 26 * (i % 2));
            interfaceIcons[i].draw(window);
        }
    }
    if (!interfaceTexts.empty())
    {
        for (size_t i = 0; i < interfaceTexts.size(); i++)
        {
            interfaceTexts[i].setOrigin(sf::Vector2f(interfaceTexts[i].getGlobalBounds().width, 0));
            interfaceTexts[i].setPosition((float)((i - i % 2) / 2) * 160 + 65 + interfaceTexts[i].getGlobalBounds().width, 5 + 26 * (i % 2));
            window.draw(interfaceTexts[i]);
        }
    }
    if (!interfacePrev.empty())
    {
        for (size_t i = 0; i < interfacePrev.size(); i++)
        {
            interfacePrev[i].setPosition((float)((i - i % 2) / 2) * 160 + 70 + interfaceTexts[i].getGlobalBounds().width, 5 + 26 * (i % 2));
            window.draw(interfacePrev[i]);
        }
    }
    if (!infoBar.empty())
    {
        for (size_t i = 0; i < infoBar.size(); i++)
        {
            infoBar[i].draw(window);
        }
    }
    if (!infoBarTexts.empty())
    {
        for (size_t i = 0; i < infoBarTexts.size(); i++)
        {
            window.draw(infoBarTexts[i]);
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
    if (!interfacePop2Vec.empty() && (button1action_button1Status == true || button1action_button2Status == true))
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
    if (!interfacePop2Vec.empty() && (button1action_button1Status == true || button1action_button2Status == true))           // po 2 kliknieciu
    {
        for (size_t i = 0; i < interfacePop2Vec.size(); i++)
        {
            if (interfacePop2Vec[i].clickedUpdate(mouse, im) == true)
            {
                interfacePopVec.clear();
                button1action_button1Status = false;
                button1action_button2Status = false;
            }

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

	if (InfobarGrab != nullptr)
	{
		infoBarTexts[0].setString("Happiness: " + std::to_string(InfobarGrab->getDataGame().Happiness));
		infoBarTexts[1].setString("Health: " + std::to_string(InfobarGrab->getDataGame().Health));
		infoBarTexts[2].setString("Public Order: " + std::to_string(InfobarGrab->getDataGame().PublicOrder));
		if (InfobarGrab->getDataGame().WaterAccess)
		{
			infoBarTexts[3].setString("Water Available");
		}
		else
		{
			infoBarTexts[3].setString("Water Unavailable");
		}
	}

}

void InterfaceManager::setResourceInterfaceValue(int index, std::string& value)
{
    interfaceTexts.at(index).setString(value);
}

InterfaceManager::~InterfaceManager()
{
}
