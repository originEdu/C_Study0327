#include "Goal.h"

AGoal::AGoal()
{
	X = 0;
	Y = 0;
	Mesh = 'G';
	ZOrder = 3;

	R = 0;
	G = 255;
	B = 0;

	Load("Data/goal.bmp");
}

AGoal::~AGoal()
{
}
