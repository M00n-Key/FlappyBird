
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
	sf::Vector2i windowSize(800, 600);

	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Flappy Bird");

	sf::Texture background_texture;
	if (!background_texture.loadFromFile("../Assets/sprites/background-day.png"))
		return EXIT_FAILURE;

	background_texture.setRepeated(true);
	sf::Sprite background(background_texture);

	sf::Vector2f backgroundScaleVector(1.01f * windowSize.x / background_texture.getSize().x, 1.01f * windowSize.y / background_texture.getSize().y);

	background.setScale(backgroundScaleVector);
	background.setPosition(sf::Vector2f(0, 0));


	sf::Vector2f bird_size(std::min(windowSize.x, windowSize.y) / 10, std::min(windowSize.x, windowSize.y) / 10);

	sf::RectangleShape bird(bird_size);
	bird.setFillColor(sf::Color::White);
	bird.setPosition((sf::Vector2f)(windowSize / 2));

	sf::Vector2f up_impulse(0, -50);
	sf::Vector2f gravity(0, 50);
	sf::Vector2f velocity(0, 0);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				velocity = up_impulse;
			}
		}

		window.clear();
		window.draw(background);
		window.draw(bird);
		window.display();

		velocity += gravity * clock.getElapsedTime().asSeconds();

		bird.move(velocity * clock.getElapsedTime().asSeconds());

		clock.restart();
	}

	return EXIT_SUCCESS;
}