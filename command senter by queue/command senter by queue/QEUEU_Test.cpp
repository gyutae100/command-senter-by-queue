// command senter by queue.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include "TemplateArryQueue.h"

#include <iostream>
using namespace std;




int main()
{
	circularQueue<long long> test1(4);

	long long inData1 = 1;
	long long inData2 = 2;
	long long inData3 = 3;
	long long inData4 = 4;
	long long inData5 = 5;
	
	//1
	if (test1.Enqueue(&inData1, 10))
	{
		cout << "삽입 성공" << endl;
	}
	else
		cout << "삽입 실패" << endl;

	//2
	if (test1.Enqueue(&inData2, 11))
	{
		cout << "삽입 성공" << endl;
	}
	else
		cout << "삽입 실패" << endl;

	//3
	if (test1.Enqueue(&inData3, 12))
	{
		cout << "삽입 성공" << endl;
	}
	else
		cout << "삽입 실패" << endl;

	//4
	if (test1.Enqueue(&inData4, 13))
	{
		cout << "삽입 성공" << endl;
	}
	else
		cout << "삽입 실패" << endl;

	//5
	if (test1.Enqueue(&inData5, 14))
	{
		cout << "삽입 성공" << endl;
	}
	else
		cout << "삽입 실패" << endl;


	//삭제
	if (test1.Dequeue(&inData1))
	{
		cout << "삭제 성공" << endl;
	}
	else
		cout << "삭제 실패" << endl;



	long long outData = -1;


	for (int j = 0; j < 4; j++)
	{
		if (test1.PeekDataByPos(&outData, j))
		{
			cout << outData << endl;
		}
		else
			cout << "peek 실패" << endl;
	}


	for (int j = 0; j < 4; j++)
	{
		if (test1.PeekTimeByPos(&outData, j))
		{
			cout << outData << endl;
		}
		else
			cout << "peek 실패" << endl;
	}

	while (true)
	{

	}
    return 0;
}

