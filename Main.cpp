
#include "TileMap.h"
#include "Building.h"

int main()
{
	TileMap Map(5, 10);
	Map.BuildTileMap();
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

        Map.update(window);
		Map.draw(window);

		// Siema z gita
		// end the current frame
		window.display();
	}

	return 0;
}