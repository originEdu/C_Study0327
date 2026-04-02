#include "Actor.h"
#include <Windows.h>
#include "Engine.h"
AActor::AActor()
{
	X = 0;
	Y = 0;
	R = 0;
	G = 0;
	B = 0;
	Mesh = ' ';
	ZOrder = 0;
}

AActor::AActor(int InX, int InY, char InMesh=' ')
	:X(InX),  Y(InY), Mesh(InMesh), ZOrder(0)
{
}

AActor::~AActor()
{
}

void AActor::Tick()
{
}
void AActor::Render()
{
	//UEngine::Instance->Draw(X, Y, Mesh);
	//UEngine::Instance->Draw(X,Y,R,G,B);
	UEngine::Instance->Draw(X, Y, Texture);
}

void AActor::SetActorLocation(int InX, int InY)
{
	X = InX;
	Y = InY;
}
