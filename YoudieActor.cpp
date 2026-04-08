#include "YoudieActor.h"
#include "TextRender.h"
AYoudieActor::AYoudieActor()
{
	TextRenderComponent->SetText("You Died.");
	X = 240;
	Y = 200;
	TextRenderComponent->ZOrder = 200;
	TextRenderComponent->bIsVisible = false;
}

AYoudieActor::~AYoudieActor()
{
}
