#include "Profiles.hpp"

Profile::Profile(string name, int score)
{
	this->name = name;
	this->score = score;
}

string Profile::getName()
{
	return this->name;
}

int Profile::getScore()
{
	return this->score;
}

void Profile::setName(string name)
{
	this->name = name;
}

void Profile::setScore(int score)
{
	this->score = score;
}