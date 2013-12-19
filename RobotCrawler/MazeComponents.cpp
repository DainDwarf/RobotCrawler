#include "MazeComponents.h"
#include <cstdlib>

MazeElem::MazeElem(int x, int y)
{
	posx = x;
	posy = y;
}

Door::Door(int x, int y) : MazeElem(x, y)
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

ElectricDoor::ElectricDoor(int x, int y, int detectRange, int timeOpen) : Door(x, y)
{
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
	if ((std::abs(x - Getx()) < range) && (std::abs(y - Gety()) < range))
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