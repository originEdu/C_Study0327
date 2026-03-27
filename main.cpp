#include<iostream>
#include"Engine.h"
int main()
{
	UEngine::GetInstance();
	UEngine::Instance->GetWorld()->Load("TestMap.txt");
	UEngine::Instance->Run();
	delete UEngine::Instance;
	
	return 0;
}