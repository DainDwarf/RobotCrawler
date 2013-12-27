#pragma once
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include "Draw.h"

class Mouse : public Drawable {
public:
	static Mouse* getInstance() {};
	virtual void press(sf::Event::MouseButtonEvent*) {}
	virtual void release(sf::Event::MouseButtonEvent*) {}
	virtual void enter() {}
	virtual void leave() {}

protected:
	Mouse() {}
	static Mouse* instance;
};

class verboseMouse : public Mouse {
public:
	static Mouse* getInstance();
	void press(sf::Event::MouseButtonEvent*);
	void release(sf::Event::MouseButtonEvent*);
	void enter();
	void leave();
	void draw(sf::RenderWindow*); //Updates the position of cursor

protected:
	verboseMouse();
	sf::CircleShape cursor;
};