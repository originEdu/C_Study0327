#include<iostream>
#include"Engine.h"
int main()
{

	//싱글톤 나중에
	UEngine* Engine0327 = new UEngine();
	Engine0327->Init_E();
	Engine0327->GetWorld()->Load("TestMap.txt");
	Engine0327->Run();
	Engine0327->Term_E();
	return 0;
}