#include "Player.h"
#include "Engine.h"
#include "ResourceManger.h"
#include "SpriteAnimationComponent.h"
#include "CollisionComponent.h"
#include "Character.h"
APlayer::APlayer()
{
	X = 1;
	Y = 1;

	//스프라이트애니메이션컴포넌트 생성
	SpriteAnimationComponent = CreateDefaultSubobject<USpriteAnimationComponent>("Sprite");
	Resource TempResource = UEngine::Instance->GetResourceManger()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	SpriteAnimationComponent->Image = TempResource.Image;
	SpriteAnimationComponent->Texture = TempResource.Texture;
	SpriteAnimationComponent->ZOrder = 20;

	//콜리전 생성
	CollisionComponent = CreateDefaultSubobject<UCollisionComponent>("Collision");
	CollisionComponent->bIsGenerateOverlab = true;
	CollisionComponent->bIsGenerateHit = true;
}

APlayer::APlayer(int InX, int InY)
{
	X = InX;
	Y = InY;
}


APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	__super::BeginPlay();

	/*OnActorBeginOverlap = [&](AActor* Other) -> void {

		};
	OnActorBeginOverlap = ProcessBeginOverlap(nullptr);*/
}

void APlayer::Tick()
{
	__super::Tick();
	SDL_Event Event = UEngine::Instance->GetEvent();
	if (Event.type == SDL_KEYDOWN )
	{
		switch (Event.key.keysym.sym)
		{
		case 'w':
			SpriteAnimationComponent->CharacterArrow = 2;
			if (PredictMove(X, Y - 1))
			{
				Y--;
			}
			break;
		case 's':
			SpriteAnimationComponent->CharacterArrow = 3;
			if (PredictMove(X, Y + 1))
			{
				Y++;
			}
			break;
		case 'a':
			SpriteAnimationComponent->CharacterArrow = 0;
			if (PredictMove(X - 1, Y))
			{
				X--;
			}
			break;
		case 'd':
			SpriteAnimationComponent->CharacterArrow = 1;
			if (PredictMove(X+1, Y))
			{
				X++;
			}
			break;
		default:
			break;
		}
	}

}

void APlayer::ReceiveHit(AActor* Other)
{
}

void APlayer::ProcessBeginOverlap(AActor* OtherActor)
{
}



