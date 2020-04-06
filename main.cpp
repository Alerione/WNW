#include "TavernBuilding.h"
#include "WellBuilding.h"
#include "StablesBuilding.h"
#include "InterfaceManager.h"
#include <algorithm>
#include <iostream>

unsigned int SCR_WIDTH = 1280;
unsigned int SCR_HEIGHT = 720;


int main()
{
    sf::Texture background;
    background.loadFromFile("water.jpg");
    background.setRepeated(true);

    sf::Sprite backgroundSprite(background);
    backgroundSprite.setTextureRect(sf::IntRect(0, 0, SCR_WIDTH, SCR_HEIGHT)); // Tekstura ma np. rozmiar 100x100, wiêc obszar jest wiêkszy od niej 10 razy

	std::vector <Building*> BuildingsList;
	int BuildingNum = 0;

    TileMap Map(10, 20);
    Map.BuildTileMap();
    sf::RenderWindow window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "My window");
    window.setFramerateLimit(60);

    double interfaceHeight = (double)SCR_HEIGHT * 0.05;
    InterfaceManager IM1((float)SCR_WIDTH, (float)SCR_HEIGHT);
    IM1.buildInterface(interfaceHeight);

    sf::View view(sf::Vector2f((float)SCR_WIDTH/2, (float)SCR_HEIGHT/2 - 2*(float)interfaceHeight), sf::Vector2f((float)SCR_WIDTH, (float)SCR_HEIGHT-2*(float)interfaceHeight));
	view.setCenter(float(Map.getColumns() * 32), float(Map.getRows() * 8));

    sf::View interfaceView(sf::Vector2f(0+ (float)SCR_WIDTH/2,0+ (float)SCR_HEIGHT/2), sf::Vector2f((float)SCR_WIDTH, (float)SCR_HEIGHT));
	window.setMouseCursorGrabbed(1);

    while (window.isOpen())
    {
        sf::Event event;
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosf = sf::Vector2f((float)mousePos.x, (float)mousePos.y);
        window.setView(interfaceView);
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.key.code == sf::Mouse::Left)
				{
                    
					if (Building::CheckBusy() == true)
					{
						BuildingsList.back()->Build();
						if(Building::CheckBusy() == false)
						std::sort(BuildingsList.begin(), BuildingsList.end(), Building::sort);
					}
                    IM1.clickedUpdateInterface(mousePosf, IM1);
				}

			}
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
				if (event.key.code == sf::Keyboard::C)
				{
					view.setCenter(float(SCR_WIDTH * 0.5), float(SCR_HEIGHT * 0.4));
					window.setView(view);
				}
				if (event.key.code == sf::Keyboard::M)
				{
					view.setCenter(float(Map.getColumns()*32), float(Map.getRows()*8));
					window.setView(view);
				}
				if (event.key.code == sf::Keyboard::S)
				{
					if (Building::CheckBusy() == false)
					{
						BuildingNum++;
						BuildingsList.resize(BuildingNum);
						BuildingsList.back() = new StablesBuilding(&Map);
					}
				}
				if (event.key.code == sf::Keyboard::T)
				{
					if (Building::CheckBusy() == false)
					{
						BuildingNum++;
						BuildingsList.resize(BuildingNum);
						BuildingsList.back() = new TavernBuilding(&Map);
					}
				}
				if (event.key.code == sf::Keyboard::W)
				{
					if (Building::CheckBusy() == false)
					{
						BuildingNum++;
						BuildingsList.resize(BuildingNum);
						BuildingsList.back() = new WellBuilding(&Map);
					}
				}
            }

        }
        window.setView(interfaceView);
        window.clear(sf::Color::Black);
        window.draw(backgroundSprite);
        window.setView(view);


        
        if (mousePos.x <= 10)
        {
            view.setCenter(view.getCenter().x - 5.0f, view.getCenter().y);
            window.setView(view);
        }
        if (mousePos.x >= (int)SCR_WIDTH-10)
        {
            view.setCenter(view.getCenter().x + 5.0f, view.getCenter().y);
            window.setView(view);
        }
        if (mousePos.y <= 10)
        {
            view.setCenter(view.getCenter().x, view.getCenter().y - 5.0f);
            window.setView(view);
        }
        if (mousePos.y >= (int)SCR_HEIGHT - 10)
        {
            view.setCenter(view.getCenter().x, view.getCenter().y + 5.0f);
            window.setView(view);
        }
        window.setView(view);
        Map.draw(window);
		Map.update(window);

		for (int build = 0; build < BuildingNum; build++)
		{
			BuildingsList[build]->draw(window);
		}
        window.setView(interfaceView);
        IM1.drawInterface(window);
        IM1.updateInterace(mousePosf, BuildingsList, Map, BuildingNum);
        window.setView(view);
        // end the current frame
        window.display();
    }

    return 0;
}