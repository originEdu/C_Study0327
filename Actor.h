#pragma once
#include <string>
#include "SDL.h"
class AActor
{
public:
	AActor();
	AActor(int InX, int InY, char InMesh);
	virtual ~AActor();

	virtual void Tick();
	virtual void Render();

	void SetActorLocation(int X, int Y);
	virtual void Load(std::string Filename);
	inline const int GetZOrder() { return ZOrder; }
protected:
	int X;
	int Y;
	int R;
	int G;
	int B;
	char Mesh;
	int ZOrder;

	SDL_Surface* Image;
	SDL_Texture* Texture;
};

