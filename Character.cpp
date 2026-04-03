#include "Character.h"
#include "Engine.h"
#include "CollisionComponent.h"

ACharacter::ACharacter()
{
}

ACharacter::~ACharacter()
{
}

bool ACharacter::PredictMove(int InX, int InY)
{
	//월드에 있는 모든 액터 확인
	for (auto Other : UEngine::Instance->GetWorld()->GetActors())
	{
		if (Other == this)
		{
			continue;
		}
		//엑터안에 모든 컴포넌트 확인
		for (auto Comopnent : Other->Components)
		{
			UCollisionComponent* OtherCollison = dynamic_cast<UCollisionComponent*>(Comopnent);
			//충돌컴포넌트 있는지 확인
			if (OtherCollison)
			{
				//충돌컴포넌트에 HIt이 true인지와 내 위치와 같은지 확인
				if (OtherCollison->bIsGenerateHit && InX == Other->GetX() && InY == Other->GetY())
				{
					ReceiveHit(Other);
					return false;
				}
			}
		}
	}
	return true;
}
