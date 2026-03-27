#pragma once
#include "Actor.h"
class APlayer :public AActor
{
public:
	APlayer();
	APlayer(int InX, int InY, char InMesh);
	virtual ~APlayer();

	virtual void Tick() override;
};

