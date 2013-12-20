#include "MapView.h"
#include "Maze.h"
#include "MazeComponents.h"
#include <iostream>

MapView* MapView::instance = 0;
Maze* MapView::mymaze = 0;
char MapView::view[MAZE_LENGTH][MAZE_HEIGHT];

MapView* MapView::getInstance(Maze* maze)
{
	if (instance == 0 || maze != mymaze) {
		instance = new MapView(maze);
		mymaze = maze;
	}
	return instance;
}

MapView::MapView(Maze* maze)
{
	for (int x = 0; x < MAZE_LENGTH;x++)
	for (int y = 0; y < MAZE_HEIGHT; y++)
		view[x][y] = maze->getPos(x,y)->print();
}

void MapView::print()
{
	std::cout.clear();
	for (int y = 0; y < MAZE_HEIGHT; y++){
		for (int x = 0; x < MAZE_LENGTH; x++){
			std::cout << view[x][y];
		}
		std::cout << std::endl;
	}
}