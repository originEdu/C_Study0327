#include "YoudieActor.h"
#include "TextRender.h"
AYoudieActor::AYoudieActor()
{
	TextRenderComponent->SetText("You Died.");
	X = 200;
	Y = 150;
}

AYoudieActor::~AYoudieActor()
{
}
