#pragma once
#include<vector>
#include "World.h"
#include <Windows.h>
#include "SDL.h"

#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")

class UEngine
{
public:
	static UEngine* Instance;
	static UEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new UEngine();
		}
		return Instance;
	}
	static int KeyCode;
	virtual ~UEngine();
	
	void Init_E();
	void Run();
	void Term_E();
	
	inline UWorld* GetWorld() const
	{
		return World;
	}
	
	//Renderer
	HANDLE ScreenBufferHandle[2];
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();
	void Draw(int InX, int InY, char InMesh);
	void Flip();
	void TermBuffer();

	void Draw(int InX, int InY, int R, int G, int B);
protected:
	UEngine();
	
	class UWorld* World;

	void Input();
	void Tick();
	void Render();
	int bIsRunning : 1;
	
	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;

};

