#pragma once
#include "Actor.h"
//추상 클래스
class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	//순수 가상 함수
	virtual void BeginPlay() =0;
	virtual void Tick() = 0;

	class AActor* Owner;
};

