#include "Wall.h"
#include "Engine.h"
#include "ResourceManger.h"
#include "SpriteComponent.h"
AWall::AWall()
{
	X = 0;
	Y = 0;

	SpriteComponent = CreateDefaultSubobject<USpriteComponent>("Sprite");
	Resource TempResource = UEngine::Instance->GetResourceManger()->LoadTexture("Data/wall.bmp");
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;
	SpriteComponent->ZOrder = 2;
}

AWall::~AWall()
{
}
