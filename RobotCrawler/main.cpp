#include "MazeGen.h"
#include "MapView.h"
#include "Maze.h"
#include <iostream>

void main()
{
	MazeGenerator* myGenerator = new StaticTestGen;

	Maze* myMaze = myGenerator->generate();

	MapView* myView = MapView::getInstance(myMaze);

	myView->print();

	std::cin.ignore();

}