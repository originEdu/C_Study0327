//#include "SDL.h"
//#include "SDL_main.h"
//#include <random>
//사용할 라이브러리 파일 추가
//#pragma comment(lib,"SDL2")
//#pragma comment(lib,"SDL2main")
//int SDL_main(int arg, char* argv[]) //SDL연습
//{
//	//랜덤구현 시작
//	//std::random_device RandomDevice; //랜덤만들어주는 녀석
//	//std::mt19937 RandomGnerator(RandomDevice());
//
//	//std::uniform_int_distribution<int> DistX(0, 400); // 특정범위에서 추출함
//	//std::uniform_int_distribution<int> DistY(0, 400);
//	//std::uniform_int_distribution<int> DistW(50, 200);
//	//std::uniform_int_distribution<int> DistH(50, 200);
//
//	//std::uniform_int_distribution<int> DistR(0, 255);
//	//std::uniform_int_distribution<int> DistG(0, 255);
//	//std::uniform_int_distribution<int> DistB(0, 255);
//	//랜덤구현 끝
//	
//
//	SDL_Init(SDL_INIT_EVERYTHING);
//
//	bool isRunning = true;
//	bool isRander = true;
//	SDL_Window* MyWindow = SDL_CreateWindow("Hello", 100, 100, 600, 600, SDL_WINDOW_SHOWN);
//	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, 0);
//	SDL_Event MyEvent;
//	while (isRunning)
//	{
//		//SDL_Event MyEvent;        // 발생한 이벤트 정보를 담을 '저장소' 선언
//		//SDL_PollEvent(&MyEvent);  // 이벤트 큐에서 가장 오래된 이벤트를 하나 꺼내옴 (꺼낼 게 있으면 1, 없으면 0 반환)
//
//		while (SDL_PollEvent(&MyEvent)) {
//			if (MyEvent.type == SDL_QUIT|| //오른쪽 위에 X버튼누르면
//				MyEvent.key.keysym.sym == SDLK_ESCAPE) { //ESC누르면 //안전한 방법(MyEvent.type == SDL_KEYDOWN && MyEvent.key.keysym.sym == SDLK_ESCAPE)
//				isRunning = false; // 창 닫기 버튼을 누르면 메인 루프 종료
//			}
//		}
//
//		if (isRander) {
//			//GPU한테 보낼 명령어 모았을뿐임
//			SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 255); //물감적시기
//			SDL_RenderClear(MyRenderer); //화면 지우기
//
//			//SDL_Rect* Rects = new SDL_Rect[100];
//			//SDL_SetRenderDrawColor(MyRenderer, DistR(RandomGnerator), DistG(RandomGnerator), DistB(RandomGnerator), 0);
//			
//			/*for (int i = 0; i < 100; i++)
//			{
//				SDL_SetRenderDrawColor(MyRenderer, DistR(RandomGnerator), DistG(RandomGnerator), DistB(RandomGnerator), 0);
//				Rects[i] = { DistX(RandomGnerator),DistY(RandomGnerator), DistW(RandomGnerator), DistH(RandomGnerator) };
//				SDL_RenderFillRect(MyRenderer, &Rects[i]);
//			}*/
//
//			//원 그리기
//			//int Radius = 100;
//			//int CenterX = 300;
//			//int CenterY = 300;
//			//int Size = 15;
//			//SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
//			//for (int Theta = 0;Theta<360;Theta+= Size)
//			//{
//			//	float Radian = (float)Theta * 3.141592f / 180.0f; //라디안화
//			//	float Radian2 = (float)(Theta+ Size) * 3.141592f / 180.0f; //라디안화
//			//	int X = Radius * SDL_cos(Radian)+ CenterX;
//			//	int Y = Radius * SDL_sin(Radian)+ CenterY;
//			//	int X2 = Radius * SDL_cos(Radian2) + CenterX;
//			//	int Y2 = Radius * SDL_sin(Radian2) + CenterY;
//			//	//SDL_RenderDrawPoint(MyRenderer, X, Y); //점으로 그리는거 한계가 있다 -> 선으로 그리자!
//			//	SDL_RenderDrawLine(MyRenderer,X,Y,X2,Y2); //선으로 그리기
//			//}
//			//원 그리기 끝
//			
//			//GPU에 보내!
//			SDL_RenderPresent(MyRenderer); //그려!
//			
//				
//		
//			//delete[] Rects; //생성한 사각형 다 지워
//			isRander = false;
//		}
//	}
//	SDL_DestroyRenderer(MyRenderer);
//	SDL_DestroyWindow(MyWindow);
//
//	SDL_Quit();
//	return 0;
//}
//