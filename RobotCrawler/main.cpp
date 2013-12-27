#include "MazeGen.h"
#include "MapView.h"
#include "Maze.h"
#include "Keyboard.h"
#include "Mouse.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

sf::Mutex windowMutex;


//Thread function for rendering thread
void renderingThread(sf::RenderWindow* window)
{
	Drawer* myDraw = new Drawer(window);
	Mouse* myMouse = verboseMouse::getInstance();
	myMouse->AddObserver(myDraw);

	while (window->isOpen())
	{
		//Display scheme.
		windowMutex.lock();
		window->clear(sf::Color::Black);
		myDraw->Draw();
		window->display();
		windowMutex.unlock();
	}
}



int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Robot Crawler");
	window.setVerticalSyncEnabled(true);

	MazeGenerator* myGenerator = new StaticTestGen;
	Maze* myMaze = myGenerator->generate();
	MapView* myView = MapView::getInstance(myMaze);
	Keyboard* myKeyboard = verboseKeyboard::getInstance();
	Mouse* myMouse = verboseMouse::getInstance();


	//Using a whole thread for rendering:
	//We need to deactivate the window first.
	window.setActive(false);
	sf::Thread thread(&renderingThread, &window);
	thread.launch();

	sf::Event event;
	//Run until window closes.
	while (window.isOpen())
	{
		//Inspecting new event
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed: //Closing the window
				//If you need to save or destroy stuff,
				//do it here.
				windowMutex.lock();
				window.close();
				windowMutex.unlock();
				break;

			case sf::Event::KeyPressed:
				myKeyboard->press(&event.key);
				break;

			case sf::Event::KeyReleased:
				myKeyboard->release(&event.key);
				break;

			case sf::Event::MouseButtonPressed:
				myMouse->press(&event.mouseButton);
				break;

			case sf::Event::MouseButtonReleased:
				myMouse->release(&event.mouseButton);
				break;

			default:
				break;
			}
		}
	}

	return 0;
}
/*void main()
{
	MazeGenerator* myGenerator = new StaticTestGen;

	Maze* myMaze = myGenerator->generate();

	MapView* myView = MapView::getInstance(myMaze);

	myView->print();

	std::cin.ignore();

}*/