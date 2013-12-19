#include "Maze.h"
#include "MazeBuilder.h"
#include "MazeComponents.h"
#include <utility>

MazeBuilder* MazeBuilder::instance = 0;
Maze* MazeBuilder::myMaze = 0;

MazeBuilder* MazeBuilder::getInstance()
{
	if (instance == 0) {
		instance = new MazeBuilder;
		myMaze = new Maze;
	}
	return instance;
}

void MazeBuilder::addRoom(int x1, int x2, int y1, int y2)
{
	//Check we don't have something invalid
	if (x1 == x2) return;
	if (y1 == y2) return;
	if (x1 < 0 || x1 >= MAZE_LENGTH) return;
	if (x2 < 0 || x2 >= MAZE_LENGTH) return;
	if (y1 < 0 || y1 >= MAZE_HEIGHT) return;
	if (y2 < 0 || y2 >= MAZE_HEIGHT) return;

	//Order the inputs
	if (x1 > x2) std::swap(x1, x2);
	if (y1 > y2) std::swap(y1, y2);

	//Create rooms inside it
	for (int x = x1+1; x < x2; x++) {
		for (int y = y1+1; y < y2; y++) {
			myMaze->setElem(x, y, new Room(x, y));
		}
	}
	//And now, place the walls around it.
	for (int x = x1; x <= x2; x++) {
		myMaze->setElem(x, y1, new Wall(x, y1));
		myMaze->setElem(x, y2, new Wall(x, y2));
	}
	for (int y = y1 + 1; y < y2; y++) {
		myMaze->setElem(x1, y, new Wall(x1, y));
		myMaze->setElem(x2, y, new Wall(x2, y));
	}
}

void MazeBuilder::connectVertically(int y1, int y2, int x)
{
	//TODO : Place windows and a door randomly
}

void MazeBuilder::connectHorizontally(int x1, int x2, int y)
{
	//TODO: Place windows and a door randomly
}

Maze* MazeBuilder::getMaze()
{
	for (int x = 0; x < MAZE_LENGTH;x++)
	for (int y = 0; y < MAZE_HEIGHT;y++)
	if (myMaze->getPos(x, y) == 0) myMaze->setElem(x, y, new Wall(x, y));
	return myMaze;
}