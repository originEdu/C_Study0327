#include <conio.h>
#include "Engine.h"
#include "World.h"
#include "SDL.h"
#include "ResourceManger.h"
#include "AudioComponent.h"

UEngine* UEngine::Instance = nullptr;

UEngine::UEngine()
{
	Init_E();
}

UEngine::~UEngine()
{
	Term_E();
}

void UEngine::Init_E()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	MyWindow = SDL_CreateWindow("Hello", 100, 100, 600, 600, SDL_WINDOW_SHOWN);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	TTF_Init(); //TTF 인잇
	Font= TTF_OpenFont("./Data/font.ttf", 24); //폰트 로딩

	//Mixer 인잇
	Mix_Init(MIX_INIT_MP3);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,4096);
	//사운드카드에 스펙 물어보는 코드	
	//int Frequency = 0;
	//Uint16 Format = 0;
	//int Channels = 0;
	//int Result = Mix_QuerySpec(&Frequency,&Format,&Channels);
	//각 스펙 Frequency, Format, Channels에 반환함
	//이를 활용하여 Mix_OpenAudio(Frequency, Format, Channels,4096); 로 사용가능

	ResourceManger = new UResourceManger();

	InitBuffer();

	World = new UWorld();

	bIsRunning = true;
}

void UEngine::Run()
{
	Uint64 LastTime = 0;
	Uint64 CurrentTime = 0;
	while (bIsRunning)
	{
		LastTime = SDL_GetTicks64();
		SDL_PollEvent(&MyEvent);
		Input();
		Tick();
		Render();
		CurrentTime = SDL_GetTicks64();
		DeltaSeconds = (float)(CurrentTime - LastTime)/1000.0f;
	}
	
}

void UEngine::Term_E()
{
	Mix_CloseAudio();
	TTF_CloseFont(Font);
	TTF_Quit();
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
	delete World;
	delete ResourceManger;
	TermBuffer();
	World = nullptr;
}

void UEngine::Input()
{
	if (MyEvent.type == SDL_QUIT ||
		MyEvent.key.keysym.sym == SDLK_ESCAPE) {
		bIsRunning = false;
	}
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();

	SDL_RenderPresent(MyRenderer);
}

void UEngine::Stop()
{
	bIsRunning = false;
}

void UEngine::InitBuffer()
{
	ScreenBufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenBufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	ConsoleCursorInfo.dwSize = 1;
	ConsoleCursorInfo.bVisible = FALSE;

	SetConsoleCursorInfo(ScreenBufferHandle[0], &ConsoleCursorInfo);
	SetConsoleCursorInfo(ScreenBufferHandle[1], &ConsoleCursorInfo);
}

void UEngine::Clear()
{
	DWORD DW;
	FillConsoleOutputCharacter(ScreenBufferHandle[ActiveScreenBufferIndex], ' ', 80 * 25, COORD{ 0, 0 }, &DW);

	SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 255);
	SDL_RenderClear(MyRenderer);
}

void UEngine::Draw(int InX, int InY, SDL_Texture* InTexture)
{
	int TileSize = 30;

	SDL_Rect MyRect = { InX * TileSize, InY * TileSize, TileSize, TileSize };
	SDL_RenderCopy(MyRenderer, InTexture, nullptr, &MyRect);
}

void UEngine::Draw(int InX, int InY, char InMesh)
{
	char MeshString[2] = { 0, };
	MeshString[0] = InMesh;

	SetConsoleCursorPosition(ScreenBufferHandle[ActiveScreenBufferIndex], COORD{ (SHORT)InX, (SHORT)InY });
	WriteFile(ScreenBufferHandle[ActiveScreenBufferIndex], MeshString, 1, NULL, NULL);
}
void UEngine::Draw(int InX, int InY, int R, int G, int B)
{
	int TileSize = 30;
	SDL_SetRenderDrawColor(MyRenderer, R, G, B, 255);
	SDL_Rect Rect = { InX * TileSize ,InY * TileSize,TileSize,TileSize };
	SDL_RenderFillRect(MyRenderer, &Rect);
}

void UEngine::Flip()
{
	SetConsoleActiveScreenBuffer(ScreenBufferHandle[ActiveScreenBufferIndex]);
	ActiveScreenBufferIndex = !ActiveScreenBufferIndex;
}

void UEngine::TermBuffer()
{
	CloseHandle(ScreenBufferHandle[0]);
	CloseHandle(ScreenBufferHandle[1]);
}

