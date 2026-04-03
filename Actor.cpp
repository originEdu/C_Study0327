#include "Actor.h"
#include <Windows.h>
#include "Component.h"
AActor::AActor()
{
	X = 0;
	Y = 0;
}

AActor::AActor(int InX, int InY)
	:X(InX),  Y(InY)
{
}

AActor::~AActor()
{
	for (auto Component : Components)
	{
		delete Component;
	}
	Components.clear();
}

void AActor::BeginPlay()
{
}

void AActor::Tick()
{
	for (auto Component : Components)
	{
		Component->Tick();
	}
}

void AActor::SetActorLocation(int InX, int InY)
{
	X = InX;
	Y = InY;
}

void AActor::ReceiveHit(AActor* Other)
{
}
