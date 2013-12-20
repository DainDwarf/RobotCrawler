#include "MazeComponents.h"
#include "Maze.h"

Maze::Maze()
{
	for (int x = 0; x < MAZE_LENGTH; x++)
	for (int y = 0; y < MAZE_HEIGHT; y++)
		map[x][y] = 0;
}

MazeElem* Maze::getPos(const int x, const int y)
{
	return map[x][y];
}

void Maze::setElem(int x, int y, MazeElem* element)
{
	//if (map[x][y] != 0) delete map[x][y];
	map[x][y] = element;
}