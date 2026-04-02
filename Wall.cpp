#include "Wall.h"
#include "Engine.h"
#include "ResourceManger.h"
AWall::AWall()
{
	X = 0;
	Y = 0;
	Mesh = '#';
	ZOrder = 1;

	R = 255;
	G = 255;
	B = 255;
	Resource TempResource = UEngine::Instance->GetResourceManger()->LoadTexture("Data/wall.bmp");
	Image = TempResource.Image;
	Texture = TempResource.Texture;
}

AWall::~AWall()
{
}
