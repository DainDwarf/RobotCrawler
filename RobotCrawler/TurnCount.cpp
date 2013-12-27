#include "TurnCount.h"
#include <list>
#include <iterator>

NeedsTimer::~NeedsTimer()
{
	TurnCount::Detach(this);
}

TurnCount* TurnCount::instance = 0;
int TurnCount::time = 0;
std::list<NeedsTimer*> TurnCount::subscribers;

TurnCount* TurnCount::getInstance()
{
	if (instance == 0) instance = new TurnCount;
	return instance;
}

int TurnCount::getTime()
{
	return time;
}

void TurnCount::Tick()
{
	time++;
	for (std::list<NeedsTimer*>::iterator i(subscribers.begin()); i != subscribers.end(); ++i){
		(*i)->Update(time);
	}
}

void TurnCount::Attach(NeedsTimer* subscriber)
{
	subscribers.push_back(subscriber);
}

void TurnCount::Detach(NeedsTimer* subscriber)
{
	for (std::list<NeedsTimer*>::iterator i(subscribers.begin()); i != subscribers.end(); ++i){
		if (subscriber == (*i)) {
			subscribers.erase(i);
			return;
		}
	}
}