#include <conio.h>
#include "Engine.h"
#include "World.h"
#include "SDL.h"

UEngine* UEngine::Instance = nullptr;
int UEngine::KeyCode = 0;

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

	SDL_SetRenderDrawColor(MyRenderer, R, G, B, 255);
	SDL_Rect Rect = { InX * 30 ,InY * 30,30,30 };
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
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, 0);

	InitBuffer();

	World = new UWorld();

	bIsRunning = true;
}

void UEngine::Run()
{
	while (bIsRunning)
	{
		SDL_PollEvent(&MyEvent);
		Input();
		Tick();
		Render();
	}
}

void UEngine::Term_E()
{
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
	delete World;
	TermBuffer();
	World = nullptr;
}

void UEngine::Input()
{
	if (MyEvent.type == SDL_QUIT ||
		MyEvent.key.keysym.sym == SDLK_ESCAPE) {
		bIsRunning = false;
	}
	if (_kbhit())
	{
		KeyCode = _getch();
	}
	if (KeyCode== SDLK_ESCAPE)
	{
		bIsRunning = false;
	}
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 255);
	SDL_RenderClear(MyRenderer);

	World->Render();

	SDL_RenderPresent(MyRenderer);
}


