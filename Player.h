#pragma once
#include "Actor.h"
#include "Character.h"
class AActor;

class APlayer :public ACharacter
{
public:
	APlayer();
	APlayer(int InX, int InY);
	virtual ~APlayer();

	virtual void BeginPlay() override;
	virtual void Tick() override;
	
	virtual void ReceiveHit(AActor* Other) override;
	void ProcessBeginOverlap(AActor* OtherActor);

	class USpriteAnimationComponent* SpriteAnimationComponent;
	class UCollisionComponent* CollisionComponent;

};

