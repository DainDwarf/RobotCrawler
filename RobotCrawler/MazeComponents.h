#pragma once
#include "Turncount.h"
#define ROOM_PRINT ' '
#define WALL_PRINT '#'
#define DOOR_PRINT '+'

class MazeElem {
public:
	virtual bool IsWalkable() = 0;
	virtual bool CanSeeThrough() = 0;
	virtual char print() = 0;
	//I am probably missing some useful things here

protected:
	MazeElem() {}
};

class Room: public MazeElem {
public:
	static Room* GetRoom(); //Flyweight
	bool IsWalkable() { return true; }
	bool CanSeeThrough() { return true; }
	char print() { return ROOM_PRINT; }

protected:
	Room() :MazeElem(){}

private:
	static Room* instance;
};

class Wall : public MazeElem {
public:
	static Wall* GetWall(); //Flyweight
	bool IsWalkable() { return false; }
	virtual bool CanSeeThrough() { return false; }
	char print() { return WALL_PRINT; }

protected:
	Wall() : MazeElem(){}

private:
	static Wall* instance;
};

class Door : public MazeElem {
public:
	Door();
	bool IsWalkable();
	virtual bool CanSeeThrough();
	virtual char print() { return DOOR_PRINT; }
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
	int posx;
	int posy;
	int range;
	int opening_time;
	int init_timer;
	bool subscribed_to_timer;
};

class WallWithWindow : public Wall{
public:
	bool CanSeeThrough() { return true; }
};