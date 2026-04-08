#include "TextRenderActor.h"
#include "TextRender.h"

ATextRenderActor::ATextRenderActor()
{
	TextRenderComponent = CreateDefaultSubobject<UTextRender>("TextRender");
}

ATextRenderActor::~ATextRenderActor()
{

}
