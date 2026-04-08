#pragma once
#include "Actor.h"

class UTextRender;

class ATextRenderActor :public AActor
{
public:
	ATextRenderActor();
	virtual ~ATextRenderActor();

	UTextRender* TextRenderComponent;
};

