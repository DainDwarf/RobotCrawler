#include "MazeComponents.h"
#include <cstdlib>

Room* Room::instance = new Room;//Might as well initialize it at compile time
Room* Room::GetRoom()
{
	return instance;
}

Wall* Wall::instance = new Wall;
Wall* Wall::GetWall()
{
	return instance;
}

Door::Door() : MazeElem()
{
	closed = true;
}

bool Door::IsWalkable()
{
	return (!closed);
}

bool Door::CanSeeThrough()
{
	return (!closed);
}

void Door::open()
{
	closed = false;
}

void Door::close()
{
	closed = true;
}

ElectricDoor::ElectricDoor(int x, int y, int detectRange, int timeOpen) : Door()
{
	posx = x;
	posy = y;
	range = detectRange;
	opening_time = timeOpen;
	init_timer = 0;
	subscribed_to_timer = false;
	/* We do not subscribe electricdoors here.
	 * They will subscribe when someone moves near it (SeeMovement)
	 */
}

bool ElectricDoor::CanSeeThrough()
{
	return true;
}


void ElectricDoor::SeeMovement(int x, int y)
{
	//First, see if it is close enough
	if ((std::abs(x - posx) < range) && (std::abs(y - posy) < range))
	{ //Now, look if the door is already subscribed (and surely opened)
		if (subscribed_to_timer)
			init_timer = TurnCount::getTime();
		else {
			Door::open();
			init_timer = TurnCount::getTime();
			TurnCount::Attach(this);
			subscribed_to_timer = true;
		}
	}
}

void ElectricDoor::Update(const int time)
{
	if (time - init_timer >= opening_time)
	{ // We haven't seen something moving for a while, time to close the door.
		Door::close();
		TurnCount::Detach(this);
		subscribed_to_timer = false;
	}
}