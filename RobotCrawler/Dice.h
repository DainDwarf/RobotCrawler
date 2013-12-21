#pragma once
#include <random>

class Dice{
public:
	Dice(int max);//gives a dice that outputs uniformly between 1 and max
	int roll(); //roll the dice

private:
	static std::default_random_engine* generator; // Uses the same generator for everyone
	std::uniform_int_distribution<int>* distribution;
};