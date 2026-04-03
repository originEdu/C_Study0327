#include "Wall.h"
#include "Engine.h"
#include "ResourceManger.h"
#include "SpriteComponent.h"
#include "CollisionComponent.h"
AWall::AWall()
{
	X = 0;
	Y = 0;

	SpriteComponent = CreateDefaultSubobject<USpriteComponent>("Sprite");
	Resource TempResource = UEngine::Instance->GetResourceManger()->LoadTexture("Data/wall.bmp");
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;
	SpriteComponent->ZOrder = 2;

	CollisionComponent = CreateDefaultSubobject<UCollisionComponent>("Collision");
	CollisionComponent->bIsGenerateOverlab = true;
	CollisionComponent->bIsGenerateHit = true;
}

AWall::~AWall()
{
}
