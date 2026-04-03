#include "ResourceManger.h"
#include "Engine.h"

UResourceManger::UResourceManger()
{
}

UResourceManger::~UResourceManger()
{
	for (auto Iter : Resources)
	{
		if (Iter.second.Image)
		{
			SDL_FreeSurface(Iter.second.Image); //이미지 삭제
		}
		if (Iter.second.Texture)
		{
			SDL_DestroyTexture(Iter.second.Texture); //텍스쳐 삭제
		}
	}
	Resources.clear(); //리스소Map 클리어
}

Resource& UResourceManger::LoadTexture(std::string Filename, bool bIsColorKey, Uint8 R, Uint8 G, Uint8 B)
{
	//이미 리소스가 있으면 그 리소스 반환
	if (Resources.find(Filename) != Resources.end())
	{
		return Resources.find(Filename)->second;
	}
	//리소스가 없으면 리소스맵에 리소스 추가 후 리소스 반환
	Resource NewResource;
	NewResource.Image = SDL_LoadBMP(Filename.c_str());
	if (bIsColorKey)
	{
		SDL_SetColorKey(NewResource.Image, SDL_TRUE, SDL_MapRGB(NewResource.Image->format, R, G, B));
	}
	NewResource.Texture = SDL_CreateTextureFromSurface(UEngine::Instance->GetRenderer(), NewResource.Image);
	Resources[Filename] = NewResource;
	return Resources[Filename];
}
