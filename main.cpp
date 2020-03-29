#include "TileMap.h"
#include "TavernBuilding.h"
#include "InterfaceElement.h"
#include <algorithm>

unsigned int SCR_WIDTH = 1900;
unsigned int SCR_HEIGHT = 1200;


int main()
{
	std::vector <Building*> BuildingsList;
	int BuildingNum = 0;

    TileMap Map(5, 10);
    Map.BuildTileMap();
    sf::RenderWindow window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "My window"/*, sf::Style::Fullscreen*/);
    window.setFramerateLimit(60);

    double interfaceHeight = (double)SCR_HEIGHT * 0.05;
    InterfaceElement Ie1(0, 0, (float)SCR_WIDTH, (float)interfaceHeight, sf::Color::Blue, true);
    InterfaceElement Ie2(0, (float)SCR_HEIGHT - (float)interfaceHeight, (float)SCR_WIDTH*(float)0.3, (float)interfaceHeight, sf::Color::Blue, true);
    InterfaceElement Ie3((float)SCR_WIDTH - (float)SCR_WIDTH * (float)0.15, (float)SCR_HEIGHT - (float)interfaceHeight, (float)SCR_WIDTH*(float)0.15, (float)interfaceHeight, sf::Color::Blue, true);

    sf::View view(sf::Vector2f((float)SCR_WIDTH/2, (float)SCR_HEIGHT/2 - 2*interfaceHeight), sf::Vector2f((float)SCR_WIDTH, (float)SCR_HEIGHT-2*interfaceHeight));
    window.setView(view);

    sf::View interfaceTopView(sf::Vector2f(0+SCR_WIDTH/2,0+SCR_HEIGHT/2), sf::Vector2f(SCR_WIDTH, SCR_HEIGHT));


    while (window.isOpen())
    {
        sf::Event event;
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
							std::sort(BuildingsList.begin(), BuildingsList.end());
					}
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
					view.setCenter(SCR_WIDTH * 0.5,SCR_HEIGHT * 0.4);
					window.setView(view);
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
            }
        }

        window.clear(sf::Color::Black);

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosf = sf::Vector2f((float)mousePos.x, (float)mousePos.y);
        if (mousePos.x <= 10)
        {
            view.setCenter(view.getCenter().x - 5.0f, view.getCenter().y);
            window.setView(view);
        }
        if (mousePos.x >= SCR_WIDTH-10)
        {
            view.setCenter(view.getCenter().x + 5.0f, view.getCenter().y);
            window.setView(view);
        }
        if (mousePos.y <= 10)
        {
            view.setCenter(view.getCenter().x, view.getCenter().y - 5.0f);
            window.setView(view);
        }
        if (mousePos.y >= SCR_HEIGHT - 10)
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
        window.setView(interfaceTopView);
        Ie1.draw(window);
        Ie2.draw(window);
        Ie3.draw(window);
        Ie1.update(mousePosf);
        window.setView(view);
        // end the current frame
        window.display();
    }

    return 0;
}