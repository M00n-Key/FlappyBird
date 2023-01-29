#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void draw(sf::RenderTarget&) = 0;
private:
	sf::Vector2f position;
	float rotate;
	sf::Vector2f scale;
};

