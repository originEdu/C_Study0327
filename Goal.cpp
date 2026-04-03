#include "Goal.h"
#include "Engine.h"
#include "ResourceManger.h"
#include "SpriteComponent.h"
AGoal::AGoal()
{
	X = 0;
	Y = 0;

	SpriteComponent = CreateDefaultSubobject<USpriteComponent>("Sprite");
	Resource TempResource = UEngine::Instance->GetResourceManger()->LoadTexture("Data/goal.bmp", true, 255, 255, 255);
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;
	SpriteComponent->ZOrder = 5;

}

AGoal::~AGoal()
{
}
