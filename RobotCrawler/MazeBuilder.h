#pragma once
#include "Maze.h"

//Is a Singleton
class MazeBuilder {
public:
	static MazeBuilder* getInstance();
	virtual void addRoom(int x1, int x2, int y1, int y2);
	virtual void connectVertically(int y1, int y2, int x);
	virtual void connectHorizontally(int x1, int x2, int y);
	virtual Maze* getMaze(); // Add Walls everywhere undefined.

protected:
	MazeBuilder();

private:
	static MazeBuilder* instance;
	static Maze* myMaze;
};