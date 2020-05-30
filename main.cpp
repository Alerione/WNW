#include "GameManager.h"

int main()
{
	GameManager Engine(1440, 960, 80, 160);
	sf::RenderWindow window(sf::VideoMode(Engine.SCR_WIDTH, Engine.SCR_HEIGHT), "Wicked New World");
	window.setFramerateLimit(60);
	Engine.grabWindow(window);
	Engine.Initialise();

    while (window.isOpen())
    {
		Engine.RenderPass();
        window.display();
    }

    return 0;
}