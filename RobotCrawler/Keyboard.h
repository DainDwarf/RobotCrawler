#pragma once
#include <SFML/Window/Event.hpp>

class Keyboard {
public:
	static Keyboard* getInstance();
	virtual void press(sf::Event::KeyEvent*) {}
	virtual void release(sf::Event::KeyEvent*) {}

protected:
	Keyboard() {}
	static Keyboard* instance;
};

class verboseKeyboard : public Keyboard {
public:
	static Keyboard* getInstance();
	void press(sf::Event::KeyEvent*);
	void release(sf::Event::KeyEvent*);

protected:
	verboseKeyboard() : Keyboard() {}
};