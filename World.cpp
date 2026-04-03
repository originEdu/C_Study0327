#include <fstream>
#include <string>
#include <algorithm>
#include "World.h"
#include "Player.h"
#include "Monster.h"
#include "Wall.h"
#include "Goal.h"
#include "Floor.h"
#include "Actor.h"
#include "Engine.h"
#include "SpriteComponent.h"
#define DEFINE_SPAWNACTOR(ParentType,Type, X, Y)\
       ParentType* New##Type = SpawnActor<Type>();\
		New##Type->SetActorLocation(X, Y);\

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
	for (auto& Actor : Actors)
	{
		delete Actor;
	}

	Actors.clear();
}

void UWorld::Tick()
{
	for (const auto& Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	UEngine::Instance->Clear();
	for (const auto Actor : Actors)
	{
		//Actor->Render(); -> 아래처럼 변경
		//모든 액터중에서 Render가능한 컴포넌트가 있으면 렌더 하세요
		for (auto Component : Actor->Components)
		{
			USpriteComponent* RenderComponent = dynamic_cast<USpriteComponent*>(Component);
			if (RenderComponent)
			{
				RenderComponent->Render();
			}
		}
	}
	UEngine::Instance->Flip();
}

void UWorld::Load(std::string Mapname)
{
	std::ifstream file(Mapname);
	if (file.is_open())
	{
		//앞에 UTF-8 BOM 제거
		if (file.peek() == 0xEF || (unsigned char)file.peek() == 0xEF) {
			file.ignore(3); // BOM 3바이트를 통째로 무시
		}
		std::string line;
		int MaxX = 0;
		int MaxY = 0;
		int X = 0;
		int Y = 0;
		while (std::getline(file, line))
		{
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == 'P')
				{
					DEFINE_SPAWNACTOR(AActor, APlayer, X, Y);
					DEFINE_SPAWNACTOR(AActor, AFloor, X, Y);
				}
				else if (line[i] == '#')
				{
					DEFINE_SPAWNACTOR(AActor, AWall, X, Y);
					DEFINE_SPAWNACTOR(AActor, AFloor, X, Y);
				}
				else if (line[i] == ' ')
				{
					DEFINE_SPAWNACTOR(AActor, AFloor, X, Y);
				}
				else if (line[i] == 'M')
				{
					DEFINE_SPAWNACTOR(AActor, AMonster, X, Y);
					DEFINE_SPAWNACTOR(AActor, AFloor, X, Y);
				}
				else if (line[i] == 'G')
				{
					DEFINE_SPAWNACTOR(AActor, AGoal, X, Y);
					DEFINE_SPAWNACTOR(AActor, AFloor, X, Y);
				}
				X++;
				if (MaxX < X)
				{
					MaxX = X;
				}
			}
			X = 0;
			Y++;
		}
		MaxY = Y;

		SDL_SetWindowSize(UEngine::Instance->GetWindow(), MaxX * 30, MaxY * 30);
	}
	
	Sort();
	//있는 라이브러리로 Sort
	/*std::sort(Actors.begin(), Actors.end(),
		[](AActor* First, AActor* Second) -> int {
			return (First->GetZOrder() < Second->GetZOrder() ? 1 : 0);
		}
	);*/
		
}

void UWorld::Sort()
{
	for (int i = 0; i < Actors.size() - 1; i++)
	{
		for (int j = 0; j < Actors.size() - 1 - i; j++)
		{
			USpriteComponent* FirstRenderComponent = nullptr;
			for (auto Component : Actors[j]->Components)
			{
				FirstRenderComponent = dynamic_cast<USpriteComponent*>(Component);
				if (FirstRenderComponent)
				{
					break;
				}
			}
			if (!FirstRenderComponent)
			{
				return;
			}
			USpriteComponent* SecondRenderComponent = nullptr;
			for (auto Component : Actors[j+1]->Components)
			{
				SecondRenderComponent = dynamic_cast<USpriteComponent*>(Component);
				if (SecondRenderComponent)
				{
					break;
				}
			}
			if (!SecondRenderComponent)
			{
				return;
			}

			if (FirstRenderComponent->ZOrder> SecondRenderComponent->ZOrder)
			{
				auto Temp = Actors[j];
				Actors[j] = Actors[j + 1];
				Actors[j + 1] = Temp;
			}

		}
	}
}
