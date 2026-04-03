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
	//전체 액터중에서 특정 타입 엑터 찾기
	template <typename T>
	T* GetActorOfClass()
	{
		for (auto Actor : Actors)
		{
			T* Target = dynamic_cast<T*>(Actor);
			if (Target)
			{
				return Target;
			}
		}
		return nullptr;
	}

	inline std::vector<AActor*>GetActors()
	{
		return Actors;
	}

protected:
	std::vector<AActor*> Actors;
	void Sort();
};

