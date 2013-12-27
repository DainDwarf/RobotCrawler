#include "Draw.h"
#include <list>
#include <iterator>

Drawable::~Drawable()
{
	for (std::list<Drawer*>::iterator i(observers.begin()); i != observers.end(); ++i)
	{
		(*i)->Detach(this);
	}
}

void Drawable::AddObserver(Drawer* observer)
{
	observers.push_front(observer);
	observer->Attach(this);
}

Drawer::Drawer(sf::RenderWindow* window)
{
	myWindow = window;
}

void Drawer::Draw()
{
	for (std::list<Drawable*>::iterator i(subscribers.begin()); i != subscribers.end(); ++i)
	{
		(*i)->draw(myWindow);
	}
}

void Drawer::Attach(Drawable* obj)
{
	subscribers.push_front(obj);
}

void Drawer::Detach(Drawable* obj)
{
	for (std::list<Drawable*>::iterator i(subscribers.begin()); i != subscribers.end(); ++i)
	if (obj == (*i)) {
		subscribers.erase(i);
		return;
	}
}