#pragma once
#include <vector>
#include <string>
#include<functional>
#include "SDL.h"
#include "Component.h"

using FActorBeginOverlap = std::function<void(class AActor* OtherActor)>;

class UComponent;

class AActor
{
public:
	AActor();
	AActor(int InX, int InY);
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();

	void SetActorLocation(int X, int Y);

	std::vector<UComponent*> Components;
	inline int GetX() const
	{
		return X;
	}
	inline int GetY() const
	{
		return Y;
	}
	FActorBeginOverlap OnActorBeginOverlap;

	virtual void ReceiveHit(class AActor* Other);

protected:
	int X;
	int Y;
	
	template <typename T>
	T* CreateDefaultSubobject(std::string ComponentName)
	{
		T* Temp = new T;
		Temp->Owner = this;
		Components.push_back(Temp);
		return Temp;
	}
};

