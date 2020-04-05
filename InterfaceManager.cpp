#include "InterfaceManager.h"

void InterfaceManager::action1()
{
	std::cout << "Button clicked is Button 1" << std::endl;
}

InterfaceManager::InterfaceManager(float scrw, float scrh)
{
    SCR_WIDTH = scrw;
    SCR_HEIGHT = scrh;
    action1Status = false;
}

void InterfaceManager::buildInterface(double interfaceHeight)
{
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
    buttonColor.r = 0;
    buttonColor.g = 0;
    buttonColor.b = 0;
    buttonColor.a = 100;

    InterfaceElement Ie2Button1(10, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
    InterfaceElement Ie2Button2(10 + (float)SCR_WIDTH*(float)0.05 + 10, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
    InterfaceElement Ie2Button3(10 + 2 * (float)SCR_WIDTH*(float)0.05 + 20, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
    InterfaceElement Ie2Button4(10 + 3 * (float)SCR_WIDTH*(float)0.05 + 30, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
    InterfaceElement Ie2Button5(10 + 4 * (float)SCR_WIDTH*(float)0.05 + 40, (float)SCR_HEIGHT - ((float)interfaceHeight + (float)interfaceHeight / (float)1.25) / 2, (float)SCR_WIDTH*(float)0.05, (float)interfaceHeight / (float)1.25, buttonColor, true);
    
    //Actions
    Ie2Button1.setAction(&InterfaceManager::action1);

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
}

void InterfaceManager::updateInterace(sf::Vector2f mouse)
{
    for (size_t i = 0; i < interfaceVec.size(); i++)
    {
        interfaceVec[i].update(mouse);
    }
}

void InterfaceManager::clickedUpdateInterface(sf::Vector2f mouse)
{
    for (size_t i = 0; i < interfaceVec.size(); i++)
    {
        interfaceVec[i].clickedUpdate(mouse);
    }
}

InterfaceManager::~InterfaceManager()
{
}
