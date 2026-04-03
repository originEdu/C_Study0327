#include "Player.h"
#include "Engine.h"
#include "ResourceManger.h"
#include "SpriteAnimationComponent.h"
APlayer::APlayer()
{
	X = 1;
	Y = 1;

	SpriteAnimationComponent = CreateDefaultSubobject<USpriteAnimationComponent>("Sprite");
	Resource TempResource = UEngine::Instance->GetResourceManger()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	SpriteAnimationComponent->Image = TempResource.Image;
	SpriteAnimationComponent->Texture = TempResource.Texture;
	SpriteAnimationComponent->ZOrder = 20;
}

APlayer::APlayer(int InX, int InY)
{
	X = InX;
	Y = InY;
}


APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	__super::Tick();
	SDL_Event Event = UEngine::Instance->GetEvent();
	if (Event.type == SDL_KEYDOWN)
	{
		switch (Event.key.keysym.sym)
		{
		case 'w':
			SpriteAnimationComponent->CharacterArrow = 2;
			Y--;
			break;
		case 's':  
			SpriteAnimationComponent->CharacterArrow = 3;
			Y++;
			break;
		case 'a': 
			SpriteAnimationComponent->CharacterArrow = 0;
			X--;
			break;
		case 'd': 
			SpriteAnimationComponent->CharacterArrow = 1;
			X++;
			break;
		default:
			break;
		}
	}

}


