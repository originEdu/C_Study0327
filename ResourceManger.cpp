#include "ResourceManger.h"
#include "Engine.h"

UResourceManger::UResourceManger()
{
}

UResourceManger::~UResourceManger()
{
	for (auto Iter:Resources)
	{
		if (Iter.second.Image)
		{
			SDL_FreeSurface(Iter.second.Image);
		}
		if (Iter.second.Texture)
		{
			SDL_DestroyTexture(Iter.second.Texture);
		}
	}
	Resources.clear();
}

Resource& UResourceManger::LoadTexture(std::string Filename, bool bIsColorKey, Uint8 R, Uint8 G, Uint8 B)
{
	if (Resources.find(Filename)!=Resources.end())
	{
		return Resources.find(Filename)->second;
	}
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
