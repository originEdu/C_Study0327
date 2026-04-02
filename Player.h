#pragma once
#include "Actor.h"
class APlayer :public AActor
{
public:
	APlayer();
	APlayer(int InX, int InY, char InMesh);
	virtual ~APlayer();

	virtual void Tick() override;
	virtual void Render() override;
	virtual void Load(std::string Filename) override;
	
	int CharacterArrow;
	float AnimationChangeTime;
	SDL_Rect SourceRect;
	SDL_Rect DestinationRect;
	int ImageIndex;
};

