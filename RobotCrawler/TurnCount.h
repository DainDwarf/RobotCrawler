#pragma once
#include <list>

//Abstract class for every class that needs the timer.
class NeedsTimer {
public:
	virtual ~NeedsTimer();
	virtual void Update(const int time) = 0;

protected:
	NeedsTimer() {}
};

//TurnCount is a kind of Singleton, and the subject of all NeedsTimer
class TurnCount {
public:
	static TurnCount* getInstance();
	static int getTime();
	static void Tick(); // Notifies all NeedsTimer objects subscribing.

	//Methods for NeedsTimer objects;
	static void Attach(NeedsTimer* subscriber);
	static void Detach(NeedsTimer* subscriber);

protected:
	TurnCount() {}

private:
	static std::list<NeedsTimer*> subscribers;
	static TurnCount* instance;
	static int time;
};