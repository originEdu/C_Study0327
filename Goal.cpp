#include "Goal.h"
#include "Engine.h"
#include "ResourceManger.h"
AGoal::AGoal()
{
	X = 0;
	Y = 0;
	Mesh = 'G';
	ZOrder = 3;

	R = 0;
	G = 255;
	B = 0;
	Resource TempResource = UEngine::Instance->GetResourceManger()->LoadTexture("Data/goal.bmp", true, 255, 255, 255);
	Image = TempResource.Image;
	Texture = TempResource.Texture;
}

AGoal::~AGoal()
{
}
