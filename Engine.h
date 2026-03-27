#pragma once
#include<vector>
#include "World.h"

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
	
	inline UWorld* GetWorld() const
	{
		return World;
	}
	
protected:
	UEngine();
	
	class UWorld* World;

	void Input();
	void Tick();
	void Render();
	int bIsRunning : 1;
	
};

