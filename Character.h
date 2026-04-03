#pragma once
#include "Actor.h"
class ACharacter :public AActor
{
public:
	ACharacter();
	virtual ~ACharacter();

	//새로갈려는 곳 갈수 있냐없냐? 
	bool PredictMove(int InX, int InY);
};

