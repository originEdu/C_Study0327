#include "SpriteComponent.h"
#include "Engine.h"
#include "Actor.h"
#include <iostream>

USpriteComponent::USpriteComponent()
{
}

USpriteComponent::~USpriteComponent()
{
}

void USpriteComponent::BeginPlay()
{
}

void USpriteComponent::Tick()
{
}

void USpriteComponent::Render()
{
	int TileSize = 30;
	SDL_Rect DestinationRect = { Owner->GetX() * TileSize, Owner->GetY() * TileSize, TileSize, TileSize };
	SDL_RenderCopy(UEngine::Instance->GetRenderer(), Texture, nullptr, &DestinationRect);
}
