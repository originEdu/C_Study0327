#include "TextRender.h"
#include "SDL_ttf.h"
#include "Engine.h"
#include "Actor.h"
UTextRender::UTextRender()
{
	
}

UTextRender::~UTextRender()
{
	SDL_FreeSurface(Surface);
	SDL_DestroyTexture(Texture);
}

void UTextRender::BeginPlay()
{
}

void UTextRender::Tick()
{
}

void UTextRender::Render()
{
	SDL_Rect DestinationRect{Owner->GetX(),Owner->GetY(),Surface->w,Surface->h};
	SDL_RenderCopy(UEngine::Instance->GetRenderer(),Texture,nullptr, &DestinationRect);
}

void UTextRender::SetText(std::string InText)
{
	Text = InText;

	//TTF에서 메모리로 등록 -> surface
	Surface = TTF_RenderText_Solid(UEngine::Instance->Font, Text.c_str(), SDL_Color{255, 0, 0, 0});
	Texture = SDL_CreateTextureFromSurface(UEngine::Instance->GetRenderer(),Surface);
}
