#pragma once
#include<vector>
#include "World.h"
#include <Windows.h>

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

protected:
	UEngine();
	
	class UWorld* World;

	void Input();
	void Tick();
	void Render();
	int bIsRunning : 1;
	

};

