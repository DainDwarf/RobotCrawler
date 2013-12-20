#pragma once
#include "MazeBuilder.h"
#include "Maze.h"

//Defines how to generate a building, different methods of building...
class MazeGenerator {
public:
	virtual Maze* generate() = 0;
};

class StaticTestGen : public MazeGenerator {
public:
	Maze* generate();
};