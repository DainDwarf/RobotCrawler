#include "Mouse.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include "Draw.h"
#include <iostream>

Mouse* Mouse::instance = 0;

verboseMouse::verboseMouse() : Mouse()
{
	cursor.setRadius(3);
	cursor.setFillColor(sf::Color::White);
	cursor.setOrigin(3, 3);
}

Mouse* verboseMouse::getInstance()
{
	if (instance == 0) instance = new verboseMouse;
	return instance;
}

void verboseMouse::draw(sf::RenderWindow* window)
{
	sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
	sf::Vector2f pos((float)localPosition.x, (float)localPosition.y);
	if (pos.x > window->getSize().x - 3) pos.x = window->getSize().x - 3;
	if (pos.x < 3) pos.x = 3;
	if (pos.y > window->getSize().y - 3) pos.y = window->getSize().y - 3;
	if (pos.y < 3) pos.y = 3;
	cursor.setPosition(pos);
	window->draw(cursor);
}

void verboseMouse::press(sf::Event::MouseButtonEvent* button)
{
	switch (button->button)
	{
	case sf::Mouse::Left:
		std::cout << "Left button pressed." << std::endl;
		break;

	case sf::Mouse::Right:
		std::cout << "Right button pressed." << std::endl;
		break;

	case sf::Mouse::Middle:
		std::cout << "Middle button pressed." << std::endl;
		break;

	default:
		std::cout << "Unkown button pressed." << std::endl;
		break;
	}
}

void verboseMouse::release(sf::Event::MouseButtonEvent* button)
{

	switch (button->button)
	{
	case sf::Mouse::Left:
		std::cout << "Left button released." << std::endl;
		break;

	case sf::Mouse::Right:
		std::cout << "Right button released." << std::endl;
		break;

	case sf::Mouse::Middle:
		std::cout << "Middle button released." << std::endl;
		break;

	default:
		std::cout << "Unkown button released." << std::endl;
		break;
	}
}

void verboseMouse::enter()
{

}

void verboseMouse::leave()
{

}