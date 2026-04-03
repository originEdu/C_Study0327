#include "SpriteAnimationComponent.h"
#include "Engine.h"
#include "Actor.h"
USpriteAnimationComponent::USpriteAnimationComponent()
{
	CharacterArrow = 1;
	AnimationChangeTime = 0;
	ImageIndex = 0;
}

USpriteAnimationComponent::~USpriteAnimationComponent()
{
}

void USpriteAnimationComponent::Tick()
{
	__super::Tick();
	float DeltaTime = UEngine::Instance->GetDeltaSeconds();
	AnimationChangeTime += DeltaTime;
	if (AnimationChangeTime > 0.5f)
	{
		ImageIndex++;
		if (ImageIndex > 4)
		{
			ImageIndex = 0;
		}
		AnimationChangeTime = 0;
	}
}

void USpriteAnimationComponent::Render()
{
	int TileSize = 30;
	int SpriteSizeX = Image->w / 5;
	int SpriteSizeY = Image->h / 5;
	SDL_Rect DestinationRect = { Owner->GetX() * TileSize, Owner->GetY() * TileSize, TileSize, TileSize };
	
	SourceRect = { SpriteSizeX * ImageIndex, SpriteSizeY * CharacterArrow, SpriteSizeX, SpriteSizeY };
	
	SDL_RenderCopy(UEngine::Instance->GetRenderer(), Texture, &SourceRect, &DestinationRect);


}
