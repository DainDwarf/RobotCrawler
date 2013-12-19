#pragma once
#define MAZE_HEIGHT 30
#define MAZE_LENGTH 100
#include "MazeComponents.h"

class Maze {
public:
	Maze();
	MazeElem* getPos(const int x, const int y);
	void setElem(int x, int y, MazeElem* element);

private:
	MazeElem* map[MAZE_LENGTH][MAZE_HEIGHT];
};