#pragma once
#include "Food.h"

class Game
{
private:
	//sets the max amout of foods at one time
	Food m_food[5];
	int score{ 0 };
	int clock{ 0 };
	//allows for changes in screen width if needed 
	int screenwidth{ 800 };
	int screenheigh{ 600 };
public:
	void Run();
};

