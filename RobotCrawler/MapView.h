#pragma once
#include "Maze.h"

//It is probably wrong to do it as a singleton.
//We need a singleton per maze.
class MapView {
public:
	static MapView* getInstance(Maze* maze);
	virtual void print();

protected:
	MapView(Maze* maze);

private:
	static MapView* instance;
	static Maze* mymaze;
	static char view[MAZE_LENGTH][MAZE_HEIGHT];
};