#include "Actor.h"
#include <Windows.h>
#include "Engine.h"
AActor::AActor()
{
	X = 0;
	Y = 0;
	R = 0;
	G = 0;
	B = 0;
	Mesh = ' ';
	ZOrder = 0;
}

AActor::AActor(int InX, int InY, char InMesh=' ')
	:X(InX),  Y(InY), Mesh(InMesh), ZOrder(0)
{
}

AActor::~AActor()
{
	SDL_FreeSurface(Image); //이미지 삭제
	SDL_DestroyTexture(Texture); //텍스쳐 삭제
}

void AActor::Tick()
{
}
void AActor::Render()
{
	//UEngine::Instance->Draw(X, Y, Mesh);
	//UEngine::Instance->Draw(X,Y,R,G,B);
	UEngine::Instance->Draw(X, Y, Texture);
}

void AActor::SetActorLocation(int InX, int InY)
{
	X = InX;
	Y = InY;
}

void AActor::Load(std::string Filename)
{
	// BMP이미지 읽어오기
	Image = SDL_LoadBMP(Filename.c_str());
	//Image(surface)에 특정색 제거
	SDL_SetColorKey(Image,SDL_TRUE,SDL_MapRGB(Image->format,255,255,255)); 
	//이미지를 텍스쳐로 변환 후 생성
	Texture = SDL_CreateTextureFromSurface(UEngine::Instance->GetRenderer(), Image);
}
