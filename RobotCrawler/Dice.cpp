#include "Dice.h"
#include <random>

//Always the same seed, TODO: change generator.
std::default_random_engine* Dice::generator = new std::default_random_engine;

Dice::Dice(int max)
{
	if (max < 1) return;
	distribution = new std::uniform_int_distribution<int>(1, max);
	//Define roll() directly using auto.
}

int Dice::roll()
{
	return (*distribution)(*generator);
}