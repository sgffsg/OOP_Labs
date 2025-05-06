#include "ShapeDrawer.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

void ShapeDrawer::DrawShapes(std::vector<IShape*> m_shapes)
{
	auto window = sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "DRAWER");
	m_canvas = new CCanvas(window);

	while (window.isOpen())
	{
		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}
		window.clear(sf::Color::White);

		for (auto const& shape : m_shapes)
		{
			shape->Draw(m_canvas);
		}
		window.display();
	}
}
