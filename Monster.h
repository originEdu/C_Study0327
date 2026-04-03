#pragma once
#include "Actor.h"
class AMonster :public AActor
{
public:
	AMonster();
	~AMonster();

	virtual void Tick() override;
	
	class USpriteComponent* SpriteComponent;
	float AnimationChangeTime;
};

