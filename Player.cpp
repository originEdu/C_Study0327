#include "Player.h"
#include "Engine.h"
#include "ResourceManger.h"
APlayer::APlayer()
{
	X = 1;
	Y = 1;
	Mesh = 'P';
	ZOrder = 4;

	R = 0;
	G = 0;
	B = 255;

	Resource TempResource = UEngine::Instance->GetResourceManger()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	Image = TempResource.Image;
	Texture = TempResource.Texture;

	CharacterArrow = 1;
	AnimationChangeTime = 0;
	ImageIndex = 0;
	SourceRect = { 0, Image->h / 5, 256 / 5, 256 / 5 };
}

APlayer::APlayer(int InX, int InY, char InMesh = 'P')
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
}


APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	__super::Tick();
	SDL_Event Event = UEngine::Instance->GetEvent();
	if (Event.type == SDL_KEYDOWN)
	{
		switch (Event.key.keysym.sym)
		{
		case 'w':
			CharacterArrow = 2;
			Y--;
			break;
		case 's':  
			CharacterArrow = 3;
			Y++;
			break;
		case 'a': 
			CharacterArrow = 0;
			X--;
			break;
		case 'd': 
			CharacterArrow = 1;
			X++;
			break;
		default:
			break;
		}
	}
	float DeltaTime = UEngine::Instance->GetDeltaSeconds();
	AnimationChangeTime += DeltaTime;
	if (AnimationChangeTime > 0.5)
	{
		ImageIndex++;
		if (ImageIndex > 4)
		{
			ImageIndex = 0;
		}
		AnimationChangeTime = 0;
	}
}


void APlayer::Render()
{
	
	int TileSize = 30;
	int SpriteSizeX = Image->w / 5;
	int SpriteSizeY = Image->h / 5;
	SDL_Rect DestinationRect = { X * TileSize, Y * TileSize, TileSize, TileSize };
	
	SourceRect = { SpriteSizeX * ImageIndex, SpriteSizeY * CharacterArrow, SpriteSizeX, SpriteSizeY };
	
	SDL_RenderCopy(UEngine::Instance->GetRenderer(), Texture, &SourceRect, &DestinationRect);
}
