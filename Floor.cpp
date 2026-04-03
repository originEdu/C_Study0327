#include "Floor.h"
#include "Engine.h"
#include "ResourceManger.h"
#include "SpriteComponent.h"
AFloor::AFloor()
{
	X = 0;
	Y = 0;

	SpriteComponent = CreateDefaultSubobject<USpriteComponent>("Sprite");
	Resource TempResource= UEngine::Instance->GetResourceManger()->LoadTexture("Data/floor.bmp");
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;
	SpriteComponent->ZOrder = 1;
}

AFloor::~AFloor()
{
}