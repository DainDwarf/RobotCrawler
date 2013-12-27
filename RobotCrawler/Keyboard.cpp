#include "Keyboard.h"
#include <SFML/Window/Event.hpp>
#include <iostream>

Keyboard* Keyboard::instance = 0;

Keyboard* Keyboard::getInstance()
{
	if (instance == 0) instance = new Keyboard;
	return instance;
}

Keyboard* verboseKeyboard::getInstance()
{
	if (instance == 0) instance = new verboseKeyboard;
	return instance;
}

void verboseKeyboard::press(sf::Event::KeyEvent* key)
{
	switch (key->code)
	{
	case sf::Keyboard::A:
		std::cout << "You pressed A";
		break;

	case sf::Keyboard::B:
		std::cout << "You pressed B";
		break;
	
	case sf::Keyboard::Down:
		std::cout << "You pressed Down";
		break;

	//etc.
	default:
		std::cout << "You pressed something unspecified." << std::endl;
		return;
	}

	if (key->alt || key->control || key->shift || key->system)
	{
		std::cout << " using a modificator." << std::endl;
	}
	else
	{
		std::cout << "." << std::endl;
	}
}

void verboseKeyboard::release(sf::Event::KeyEvent* key)
{
	std::cout << "You released the key " << key->code << "." << std::endl;
}