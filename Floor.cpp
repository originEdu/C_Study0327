#include "Floor.h"
AFloor::AFloor()
{
	X = 0;
	Y = 0;
	Mesh = ' ';
	ZOrder = 0;

	R=0;
	G=0;
	B=0;

	Load("Data/floor.bmp");
}

AFloor::~AFloor()
{
}