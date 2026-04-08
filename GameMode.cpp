#include "GameMode.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"
#include "Engine.h"
#include "World.h"
#include "YoudieActor.h"
#include "TextRender.h"
#pragma execution_character_set("utf-8")
AGameMode::AGameMode()
{
}

AGameMode::~AGameMode()
{
}

void AGameMode::Tick()
{
	__super::Tick();
	//안좋은 방법이지만
	//매 틱마다 플레이어와 몬스터
	//플레이어와 목표
	//겹치는지 확인
	APlayer* Player = UEngine::Instance->GetWorld()->GetActorOfClass<APlayer>();
	AMonster* Monster = UEngine::Instance->GetWorld()->GetActorOfClass<AMonster>();
	AGoal* Goal = UEngine::Instance->GetWorld()->GetActorOfClass<AGoal>();
	
	if (Player && Goal)
	{
		if ((Player->GetX() == Goal->GetX()) &&(Player->GetY() == Goal->GetY()))
		{
			SDL_Log("게임 끝!");
			UEngine::Instance->Stop();
		}
	}
	if (Player && Monster)
	{
		if ((Player->GetX() == Monster->GetX()) && (Player->GetY() == Monster->GetY()))
		{
			AYoudieActor* TextActor = UEngine::Instance->GetWorld()->GetActorOfClass<AYoudieActor>();
			if (TextActor)
			{
				TextActor->TextRenderComponent->bIsVisible = true;
			}
			
			SDL_Log("죽었다!");
			
			//UEngine::Instance->Stop();
		}
	}
}
