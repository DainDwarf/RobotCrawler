#include "MazeGen.h"
#include "MazeBuilder.h"
#include "Maze.h"

Maze* StaticTestGen::generate () {
	MazeBuilder* builder = MazeBuilder::getInstance();

	builder->addRoom(0, 30, 0, 14);
	builder->addRoom(30, 60, 0, 14);
	builder->addRoom(60, MAZE_LENGTH, 0, 14);
	builder->addRoom(0, MAZE_LENGTH, 14, 16); //Long Hallway
	builder->addRoom(0, 30, 16, MAZE_HEIGHT);
	builder->addRoom(30, 60, 16, MAZE_HEIGHT);
	builder->addRoom(60, MAZE_LENGTH, 16, MAZE_HEIGHT);

	builder->connectHorizontally(0, 30, 14);
	builder->connectHorizontally(30, 60, 14);
	builder->connectHorizontally(60, MAZE_LENGTH, 14);
	builder->connectHorizontally(0, 30, 16);
	builder->connectHorizontally(30, 60, 16);
	builder->connectHorizontally(60, MAZE_LENGTH, 16);

	builder->connectVertically(0, 14, 30);
	builder->connectVertically(16, MAZE_HEIGHT, 60);

	return builder->getMaze();
}