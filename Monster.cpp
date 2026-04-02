#include "Monster.h"
#include "Engine.h"

AMonster::AMonster()
{
	X = 0;
	Y = 0;
	Mesh = 'M';
	ZOrder = 2;

	R = 255;
	G = 0;
	B = 0;

	Load("Data/monster.bmp");
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
