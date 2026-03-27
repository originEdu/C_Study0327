#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include "World.h"
#include "Player.h"
#include "Monster.h"
#include "Wall.h"
#include "Goal.h"
#include "Actor.h"
#define DEFINE_SPAWNACTOR(ParentType,Type, X, Y)\
       ParentType* New##Type = SpawnActor<Type>();\
		New##Type->SetActorLocation(X, Y);\

UWorld::UWorld()
{
	SpawnActor<APlayer>();
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
	for (const auto& Actor : Actors)
	{
		Actor->Render();
	}
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
		int X = 0;
		int Y = 0;
		while (std::getline(file, line))
		{
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == 'P')
				{
					DEFINE_SPAWNACTOR(AActor, APlayer, X, Y);
					/*AActor* NewActor = SpawnActor<APlayer>();
					NewActor->SetActorLocation(X, Y);*/
				}
				else if (line[i] == '#')
				{
					DEFINE_SPAWNACTOR(AActor, AWall, X, Y);
				/*	AActor* NewWall = SpawnActor<AWall>();
					NewWall->SetActorLocation(X, Y);*/
				}
				else if (line[i] == ' ')
				{
					std::cout << ' ';
					//AActor* NewFloor = SpawnActor<AFloor>();
					//NewFloor->SetActorLocation(X, Y);
				}
				else if (line[i] == 'M')
				{
					DEFINE_SPAWNACTOR(AActor, AMonster, X, Y);
					/*AActor* NewMonster = SpawnActor<AMonster>();
					NewMonster->SetActorLocation(X, Y);*/
				}
				else if (line[i] == 'G')
				{
					DEFINE_SPAWNACTOR(AActor, AGoal, X, Y);
					/*AActor* NewGoal = SpawnActor<AGoal>();
					NewGoal->SetActorLocation(X, Y);*/
				}
				X++;
			}
			X = 0;
			Y++;
		}
	}
	//있는 라이브러리로 Sort
	//std::sort(Actors.begin(), Actors.end(),
	//	[](AActor* First, AActor* Second)->{

	//});
		
}

void UWorld::Sort()
{
	for (int i = 0; i < Actors.size() - 1; i++)
	{
		for (int j = 0; j < Actors.size() - 1 - i; j++)
		{
			if (Actors[j]->GetZOrder()< Actors[j+1]->GetZOrder())
			{
				auto Temp = Actors[j];
				Actors[j] = Actors[j + 1];
				Actors[j + 1] = Temp;
			}

		}
	}
}
