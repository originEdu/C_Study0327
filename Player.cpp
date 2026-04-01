#include "Player.h"
#include "Engine.h"

APlayer::APlayer() 
{
	X = 1;
	Y = 1;
	Mesh = 'P';
	ZOrder = 4;

	R = 0;
	G = 0;
	B = 255;
}

APlayer::APlayer(int InX, int InY, char InMesh='P')
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
}


APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	__super::Tick();
	if (UEngine::KeyCode == 'w')
	{
		Y--;
	}
	if (UEngine::KeyCode == 's')
	{
		Y++;
	}
	if (UEngine::KeyCode == 'a')
	{
		X--;
	}
	if (UEngine::KeyCode == 'd')
	{
		X++;
	}

	UEngine::KeyCode = 0;
}

//void APlayer::Render() 
//{
//	__super::Render();
//}
