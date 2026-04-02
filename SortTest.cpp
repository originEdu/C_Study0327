//#include<iostream>
//void SelectionSort(int* Data, int Size, char Order);
//void BubbleSort(int* Data, int Size, bool (*cmp)(int, int));
//bool Compare(int a, int b, char Order);
//bool Asc(int a, int b);
//bool Desc(int a, int b);
//int main()
//{
//Sort + 함수 포인터
//int Data[10] = { 9,2,3,4,5,6,7,8,1,10 };

//SelectionSort(Data, 10, 'A'); // 오름차순
//for (int i = 0; i < 10; i++)
//{
//	std::cout << Data[i] << ", ";
//}
//std::cout << std::endl;
//SelectionSort(Data, 10, 'D'); // 내림차순
//for (int i = 0; i < 10; i++)
//{
//	std::cout << Data[i] << ", ";
//}
//std::cout << std::endl;
////버블정렬
//BubbleSort(Data, 10, Asc);
//for (int i = 0; i < 10; i++)
//{
//	std::cout << Data[i] << ", ";
//}
//std::cout << std::endl;
//BubbleSort(Data, 10, Desc);
//for (int i = 0; i < 10; i++)
//{
//	std::cout << Data[i] << ", ";
//}
//	return 0;
//}
//bool Compare(int a, int b, char Order) {
//	return (Order == 'A') ? (a > b) : (a < b);
//}
//
//void SelectionSort(int* Data, int Size, char Order)
//{
//	for (int i = 0; i < Size - 1; i++)
//	{
//		for (int j = i + 1; j < Size; j++)
//		{
//			if (Compare(Data[i], Data[j], Order))
//			{
//				int Temp = Data[i];
//				Data[i] = Data[j];
//				Data[j] = Temp;
//			}
//		}
//	}
//}
//
//bool Asc(int a, int b) { return a > b; }
//bool Desc(int a, int b) { return a < b; }
//
//void BubbleSort(int* Data, int Size, bool (*cmp)(int, int))
//{
//	for (int i = 0; i < Size - 1; i++)
//	{
//		for (int j = 0; j < Size - 1 - i; j++)
//		{
//			if (cmp(Data[j], Data[j + 1]))
//			{
//				int Temp = Data[j];
//				Data[j] = Data[j + 1];
//				Data[j + 1] = Temp;
//			}
//
//		}
//	}
//}


