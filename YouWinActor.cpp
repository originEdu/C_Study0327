#include "YouWinActor.h"
#include "TextRender.h"

AYouWinActor::AYouWinActor()
{
	TextRenderComponent->SetText("You Win!");
	X = 240;
	Y = 200;
	TextRenderComponent->ZOrder = 200;
	TextRenderComponent->bIsVisible = false;
}

AYouWinActor::~AYouWinActor()
{
}
