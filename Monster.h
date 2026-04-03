#pragma once
#include "Actor.h"
#include "Character.h"
class AMonster :public ACharacter
{
public:
	AMonster();
	~AMonster();

	virtual void Tick() override;
	
	class USpriteComponent* SpriteComponent;
	float AnimationChangeTime;

	class UCollisionComponent* CollisionComponent;
};

