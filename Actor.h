#pragma once
#include <vector>
#include <string>
#include "SDL.h"
#include "Component.h"
class UComponent;

class AActor
{
public:
	AActor();
	AActor(int InX, int InY, char InMesh);
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();

	void SetActorLocation(int X, int Y);
	//inline const int GetZOrder() { return ZOrder; }
	std::vector<UComponent*> Components;
	inline int GetX() const
	{
		return X;
	}
	inline int GetY() const
	{
		return Y;
	}
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

	//int R;
	//int G;
	//int B;
	//char Mesh;
	//int ZOrder;

	//SDL_Surface* Image;
	//SDL_Texture* Texture;


};

