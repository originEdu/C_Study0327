#include "Floor.h"
#include "Engine.h"
#include "ResourceManger.h"
AFloor::AFloor()
{
	X = 0;
	Y = 0;
	Mesh = ' ';
	ZOrder = 0;

	R=0;
	G=0;
	B=0;
	Resource TempResource= UEngine::Instance->GetResourceManger()->LoadTexture("Data/floor.bmp");
	Image = TempResource.Image;
	Texture = TempResource.Texture;
}

AFloor::~AFloor()
{
}