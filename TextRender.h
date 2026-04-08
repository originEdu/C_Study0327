#pragma once
#include<string>
#include "Component.h"
#include "RenderableComponent.h"

struct SDL_Surface;
struct SDL_Texture;

class UTextRender :public UComponent, public IRenderableComponent
{
public:
	UTextRender();
	virtual ~UTextRender();

	virtual void BeginPlay() override;
	virtual void Tick() override;

	virtual void Render() override;

	void SetText(std::string InText);

protected:
	std::string Text;

	SDL_Surface* Surface;
	SDL_Texture* Texture;
};

