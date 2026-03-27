#pragma once
#include "World.h"
class UEngine
{
public:
	UEngine();
	virtual ~UEngine();
	
	void Init_E();
	void Run();
	void Term_E();
	
	inline UWorld* GetWorld() const
	{
		return World;
	}

protected:
	void Input();
	void Tick();
	void Render();
	int bIsRunning : 1;
	class UWorld* World;
};

