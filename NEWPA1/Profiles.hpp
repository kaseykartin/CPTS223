#pragma once

#include <iostream>
#include <string>

using namespace std;

class Profile {
public:

	Profile(string name = "", int score = 0);

	~Profile() {};

	string getName();
	int getScore();

	void setName(string name);
	void setScore(int score);



private:

	string name;
	int score;

};