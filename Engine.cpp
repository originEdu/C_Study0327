#include "Engine.h"
#include "World.h"

UEngine::UEngine()
{
	Init_E();
}

UEngine::~UEngine()
{
	Term_E();
}

void UEngine::Init_E()
{
	World = new UWorld;
	bIsRunning = 1;
}

void UEngine::Run()
{
	//while (bIsRunning)
	{
		//Input();
		Tick();
		Render();
	}
}

void UEngine::Term_E()
{
	delete World;
}

void UEngine::Input()
{
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}


