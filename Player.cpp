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

APlayer::APlayer(int InX, int InY, char InMesh = 'P')
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
	SDL_Event Event = UEngine::Instance->GetEvent();
	if (Event.type == SDL_KEYDOWN)
	{
		switch (Event.key.keysym.sym)
		{
		case 'w':
			Y--;
			break;
		case 's':  
			Y++;
			break;
		case 'a': 
			X--;
			break;
		case 'd': 
			X++;
			break;
		default:
			break;
		}
	}

}

//void APlayer::Render() 
//{
//	__super::Render();
//}
