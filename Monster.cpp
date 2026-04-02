#include "Monster.h"
#include "Engine.h"
#include "ResourceManger.h"

AMonster::AMonster()
{
	X = 0;
	Y = 0;
	Mesh = 'M';
	ZOrder = 2;

	R = 255;
	G = 0;
	B = 0;

	Resource TempResource = UEngine::Instance->GetResourceManger()->LoadTexture("Data/monster.bmp",true,255,255,255);
	Image = TempResource.Image;
	Texture = TempResource.Texture;
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	__super::Tick();
	float DeltaTime = UEngine::Instance->GetDeltaSeconds();
	AnimationChangeTime += DeltaTime;
	if (AnimationChangeTime > 0.5)
	{
		switch (rand() % 5)
		{
		case 0:
			Y--;
			break;
		case 1:
			Y++;
			break;
		case 2:
			X--;
			break;
		case 3:
			X++;
			break;
		default:
			break;
		}
		AnimationChangeTime = 0;
	}
	
}
