#pragma once
#include "SDL.h"
#include "Component.h"
#include "RenderableComponent.h"

class USpriteComponent :public UComponent, IRenderableComponent
{
public:
	USpriteComponent();
	virtual ~USpriteComponent();

	virtual void BeginPlay() override;
	virtual void Tick() override;

	virtual void Render() override;

	int ZOrder = 0;

	SDL_Surface* Image;
	SDL_Texture* Texture;
};

