#include "Monster.h"
#include "Engine.h"
#include "ResourceManger.h"
#include "SpriteComponent.h"
#include "CollisionComponent.h"
#include "Player.h"
AMonster::AMonster()
{
	X = 0;
	Y = 0;

	SpriteComponent = CreateDefaultSubobject<USpriteComponent>("Sprite");
	Resource TempResource = UEngine::Instance->GetResourceManger()->LoadTexture("Data/monster.bmp", true, 255, 255, 255);
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;
	SpriteComponent->ZOrder = 10;

	//콜리전 생성
	CollisionComponent = CreateDefaultSubobject<UCollisionComponent>("Collision");
	CollisionComponent->bIsGenerateOverlab = true;
	CollisionComponent->bIsGenerateHit = false;
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	__super::Tick();
	float DeltaTime = UEngine::Instance->GetDeltaSeconds();
	AnimationChangeTime += DeltaTime;
	if (AnimationChangeTime > 0.5f)
	{
		switch (rand() % 5)
		{
		case 0:
			if (PredictMove(X, Y - 1))
			{
				Y--;
			}
			
			break;
		case 1:
			if (PredictMove(X, Y + 1))
			{
				Y++;
			}
			break;
		case 2:
			if (PredictMove(X -1 , Y))
			{
				X--;
			}
			break;
		case 3:
			if (PredictMove(X + 1, Y))
			{
				X++;
			}
			break;
		default:
			break;
		}
		AnimationChangeTime = 0;
	}
	
}
