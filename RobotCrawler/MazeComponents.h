#pragma once
#include "Turncount.h"

class MazeElem {
public:
	virtual bool IsWalkable() = 0;
	virtual bool CanSeeThrough() = 0;
	int Getx() const { return posx; }
	int Gety() const { return posy; }
	//I am probably missing some useful things here

protected:
	MazeElem(int x, int y);

private:
	int posx;
	int posy;
};

class Room: public MazeElem {
public:
	Room(int x, int y) : MazeElem(x, y) {}
	bool IsWalkable() { return true; }
	bool CanSeeThrough() { return true; }
};

class Wall : public MazeElem {
public:
	Wall(int x, int y) : MazeElem(x, y){}
	bool IsWalkable() { return false; }
	virtual bool CanSeeThrough() { return false; }
};

class Door : public MazeElem {
public:
	Door(int x, int y);
	bool IsWalkable();
	virtual bool CanSeeThrough();
	virtual void open();
	virtual void close();

private:
	bool closed;
};

class ElectricDoor : public Door, public NeedsTimer
{
public:
	ElectricDoor(int x, int y, int detectRange, int timeOpen);
	bool CanSeeThrough();
	//Are those necessary?
	void open() {}
	void close() {}
	//Range of movement detection + time it stays open
	void Update(const int time);
	void SeeMovement(int x, int y);
	//If someone moves near enough, then it works.
	//This HAS to be called when someone sees the door.

private:
	int range;
	int opening_time;
	int init_timer;
	bool subscribed_to_timer;
};

class WallWithWindow : public Wall{
public:
	bool CanSeeThrough() { return true; }
};