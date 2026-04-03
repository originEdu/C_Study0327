#pragma once
#include "SpriteComponent.h"
class USpriteAnimationComponent : public USpriteComponent
{
public:
	USpriteAnimationComponent();
	virtual ~USpriteAnimationComponent();

	virtual void Tick() override;

	virtual void Render() override;


	int ImageIndex;
	int CharacterArrow;
	float AnimationChangeTime;
	SDL_Rect SourceRect;
	SDL_Rect DestinationRect;

};

