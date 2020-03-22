
#include "TileMap.h"
#include "Building.h"


int main()
{
	TileMap Map1(5, 10);
	Map1.BuildTileMap();

	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	window.setFramerateLimit(10);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		Map1.draw(window);

		// end the current frame
		window.display();
	}

	return 0;
}