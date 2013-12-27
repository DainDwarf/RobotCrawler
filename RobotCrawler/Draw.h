#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>

class Drawer;

class Drawable {
	//A pure virtual class for objects that accepts to be drawn
public:
	virtual ~Drawable();
	virtual void draw(sf::RenderWindow*) = 0;
	virtual void AddObserver(Drawer*);

private:
	std::list<Drawer*> observers;
};

class Drawer {
	//The probably single drawer that draw all objects on the SFML window
public:
	Drawer(sf::RenderWindow* window);
	void Draw();

private:
	friend class Drawable;
	void Attach(Drawable*);
	void Detach(Drawable*);

private:
	sf::RenderWindow* myWindow;
	std::list<Drawable*> subscribers;
};