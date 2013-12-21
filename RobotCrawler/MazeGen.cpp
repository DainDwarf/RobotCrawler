#include "MazeGen.h"
#include "MazeBuilder.h"
#include "Maze.h"

Maze* StaticTestGen::generate () {
	MazeBuilder* builder = MazeBuilder::getInstance();

	builder->addRoom(0, 30, 0, 14);
	builder->addRoom(30, 60, 0, 14);
	builder->addRoom(60, MAZE_LENGTH-1, 0, 14);
	builder->addRoom(0, MAZE_LENGTH-1, 14, 16); //Long Hallway
	builder->addRoom(0, 30, 16, MAZE_HEIGHT-1);
	builder->addRoom(30, 60, 16, MAZE_HEIGHT-1);
	builder->addRoom(60, MAZE_LENGTH-1, 16, MAZE_HEIGHT-1);

	builder->connectHorizontally(1, 29, 14);
	builder->connectHorizontally(31, 59, 14);
	builder->connectHorizontally(61, MAZE_LENGTH-2, 14);
	builder->connectHorizontally(1, 29, 16);
	builder->connectHorizontally(31, 59, 16);
	builder->connectHorizontally(61, MAZE_LENGTH-2, 16);

	builder->connectVertically(1, 13, 30);
	builder->connectVertically(17, MAZE_HEIGHT-2, 60);

	return builder->getMaze();
}