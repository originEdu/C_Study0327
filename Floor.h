#pragma once
#include "Actor.h"

//전방선언
class USpriteComponent;

class AFloor :public AActor
{
public:
	AFloor();
	virtual ~AFloor();

	USpriteComponent* SpriteComponent;
};

