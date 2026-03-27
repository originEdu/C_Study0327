#pragma once
#include<vector>
#include<string>
#include "Actor.h"

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void Tick();
	void Render();
	void Load(std::string Mapname);

	template <typename T>
	AActor* SpawnActor()
	{
		AActor* NewActor = new T;
		Actors.push_back(NewActor);

		return NewActor;
	}

	inline std::vector<AActor*>GetActors()
	{
		return Actors;
	}

protected:
	std::vector<AActor*> Actors;
	void Sort();
};

