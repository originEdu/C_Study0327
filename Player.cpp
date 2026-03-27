#include "Player.h"


APlayer::APlayer() 
{
	X = 1;
	Y = 1;
	Mesh = 'P';
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

//void APlayer::Render() 
//{
//	__super::Render();
//}
