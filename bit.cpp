//#include<iostream>
//int SDL_main(int arg, char* argv[])
//{
//
//	int N = 0;
//	unsigned long long X = 1;
//	unsigned long long XOR = 0;
//
//	std::cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		std::cin >> X;
//
//		for (int j = 0; j < 63; j++)
//		{
//			//if (X <= std::pow(2, j))
//			unsigned long long NPOT = (1 << j);
//			if (X <= NPOT)
//			{
//				XOR = XOR ^ NPOT;
//				break;
//			}
//		}
//	}
//
//
//	std::cout << XOR << std::endl;
//	return 0;
//}