#include<iostream>
#include"Engine.h"
#include "SDL.h"
#include "SDL_main.h"
#include <random>
//사용할 라이브러리 파일 추가
#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")

int SDL_main(int arg, char* argv[])
{
	std::random_device RandomDevice; //랜덤만들어주는 녀석
	std::mt19937 RandomGnerator(RandomDevice());

	std::uniform_int_distribution<int> DistX(0, 400); // 특정범위에서 추출함
	std::uniform_int_distribution<int> DistY(0, 400);
	std::uniform_int_distribution<int> DistW(50, 200);
	std::uniform_int_distribution<int> DistH(50, 200);

	std::uniform_int_distribution<int> DistR(0, 255);
	std::uniform_int_distribution<int> DistG(0, 255);
	std::uniform_int_distribution<int> DistB(0, 255);



	SDL_Init(SDL_INIT_EVERYTHING);

	bool isRunning = true;
	bool isRander = true;
	SDL_Window* MyWindow = SDL_CreateWindow("Hello", 100, 100, 600, 600, SDL_WINDOW_SHOWN);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, 0);
	SDL_Event MyEvent;
	while (isRunning)
	{
		//SDL_Event MyEvent;        // 발생한 이벤트 정보를 담을 '저장소' 선언
		//SDL_PollEvent(&MyEvent);  // 이벤트 큐에서 가장 오래된 이벤트를 하나 꺼내옴 (꺼낼 게 있으면 1, 없으면 0 반환)

		while (SDL_PollEvent(&MyEvent)) {
			if (MyEvent.type == SDL_QUIT|| //오른쪽 위에 X버튼누르면
				MyEvent.key.keysym.sym == SDLK_ESCAPE) { //ESC누르면 //안전한 방법(MyEvent.type == SDL_KEYDOWN && MyEvent.key.keysym.sym == SDLK_ESCAPE)
				isRunning = false; // 창 닫기 버튼을 누르면 메인 루프 종료
			}
		}
		if (isRander) {
			//GPU한테 보낼 명령어 모았을뿐임
			SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 255); //물감적시기
			SDL_RenderClear(MyRenderer); //화면 지우기

			SDL_Rect* Rects = new SDL_Rect[100];

			for (int i = 0; i < 100; i++)
			{
				SDL_SetRenderDrawColor(MyRenderer, DistR(RandomGnerator), DistG(RandomGnerator), DistB(RandomGnerator), 0);
				Rects[i] = { DistX(RandomGnerator),DistY(RandomGnerator), DistW(RandomGnerator), DistH(RandomGnerator) };
				SDL_RenderFillRect(MyRenderer, &Rects[i]);
			}

			//GPU에 보내!
			SDL_RenderPresent(MyRenderer); //그려!

			delete[] Rects; //생성한 사각형 다 지워
			isRander = false;
		}
	}
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);

	SDL_Quit();
	return 0;
}



void SelectionSort(int* Data, int Size, char Order);
void BubbleSort(int* Data, int Size, bool (*cmp)(int, int));
bool Compare(int a, int b, char Order);
bool Asc(int a, int b);
bool Desc(int a, int b);
//int main()
//{
//	UEngine::GetInstance();
//	UEngine::Instance->GetWorld()->Load("TestMap.txt");
//	UEngine::Instance->Run();
//	delete UEngine::Instance;
//
//	//Sort + 함수 포인터
//	//int Data[10] = { 9,2,3,4,5,6,7,8,1,10 };
//
//	//SelectionSort(Data, 10, 'A'); // 오름차순
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	std::cout << Data[i] << ", ";
//	//}
//	//std::cout << std::endl;
//	//SelectionSort(Data, 10, 'D'); // 내림차순
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	std::cout << Data[i] << ", ";
//	//}
//	//std::cout << std::endl;
//	////버블정렬
//	//BubbleSort(Data, 10, Asc);
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	std::cout << Data[i] << ", ";
//	//}
//	//std::cout << std::endl;
//	//BubbleSort(Data, 10, Desc);
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	std::cout << Data[i] << ", ";
//	//}
//
//	return 0;
//}

bool Compare(int a, int b, char Order) {
	return (Order == 'A') ? (a > b) : (a < b);
}

void SelectionSort(int* Data, int Size, char Order)
{
	for (int i = 0; i < Size - 1; i++)
	{
		for (int j = i + 1; j < Size; j++)
		{
			if (Compare(Data[i], Data[j], Order))
			{
				int Temp = Data[i];
				Data[i] = Data[j];
				Data[j] = Temp;
			}
		}
	}
}

bool Asc(int a, int b) { return a > b; }
bool Desc(int a, int b) { return a < b; }

void BubbleSort(int* Data, int Size, bool (*cmp)(int, int))
{
	for (int i = 0; i < Size - 1; i++)
	{
		for (int j = 0; j < Size - 1 - i; j++)
		{
			if (cmp(Data[j], Data[j + 1]))
			{
				int Temp = Data[j];
				Data[j] = Data[j + 1];
				Data[j + 1] = Temp;
			}

		}
	}
}