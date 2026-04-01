#include "Actor.h"
#include<iostream>
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
	//COORD pos;
	//pos.X = (SHORT)X; // 가로 위치
	//pos.Y = (SHORT)Y; // 세로 위치
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	//std::cout << Mesh;

	UEngine::Instance->Draw(X, Y, Mesh);
	UEngine::Instance->Draw(X,Y,R,G,B);
}

void AActor::SetActorLocation(int InX, int InY)
{
	X = InX;
	Y = InY;
}
