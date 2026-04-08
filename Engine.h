#pragma once
#include<vector>
#include "World.h"
#include <Windows.h>
#include "SDL.h"
#include "ResourceManger.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"


#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")
#pragma comment(lib,"SDL2_ttf")
#pragma comment(lib,"SDL2_mixer")

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
	virtual ~UEngine();

	void Init_E();
	void Run();
	void Term_E();

	void Stop();

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
	void Draw(int InX, int InY, int R, int G, int B);
	void Draw(int InX, int InY, SDL_Texture* InTexture);
	void Flip();
	void TermBuffer();

	//key입력 변경
	inline const SDL_Event& GetEvent()
	{
		return MyEvent;
	}
	
	inline float GetDeltaSeconds() const
	{
		return DeltaSeconds;
	}

	inline SDL_Renderer* GetRenderer() const
	{
		return MyRenderer;
	}
	inline SDL_Window* GetWindow() const
	{
		return MyWindow;
	}
	inline UResourceManger* GetResourceManger() const
	{
		return ResourceManger;
	}

	//get,set함수 그만만들기 위해 public으로
	TTF_Font* Font;
protected:
	UEngine();
	
	class UWorld* World;
	class UResourceManger* ResourceManger;
	void Input();
	void Tick();
	void Render();
	int bIsRunning : 1;
	
	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;

	float DeltaSeconds;
};

