//�̿�
//	q �κ� dequeue ( o , index) �κ� ���� �� ��!!


#pragma once


#include "stdafx.h"

#include "TemplateArryQueue.h"

#include <iostream>

#include <windows.h>


#include "stdio.h"
#include "time.h"


//for kbhit
#include <conio.h>
using namespace std;



//���� ����ü
typedef struct UnitInfo {
	int hp; //���� ü��
	char name[10]; //���� �̸�
	long long  creationTime; //���� ���� �ð�
}UnitInfo;

//Ŀ��� ���� ����
typedef enum comandInfo
{
	totalQueueCnt = 10,
	totalUnitCnt = 10

}comandInfo;

//���� ����
UnitInfo units[totalUnitCnt] = {
	{ 10, "gyutae0", 10},
	{ 20, "gyutae1", 20 },
	{ 30, "gyutae2", 30 },
	{ 40, "gyutae3", 40 },
	{ 50, "gyutae4", 50 },
	{ 60, "gyutae5", 60 },
	{ 70, "gyutae6", 70 },
	{ 80, "gyutae7", 80 },
	{ 90, "gyutae8", 90 },
	{ 100, "gyutae9", 100 }
};


//�Լ� ����
void DisplayScreen(circularQueue<UnitInfo> * commandSenter);




//���� Ŭ��
static clock_t current_tick;
static double currentSec_sec;


int main()
{

	//Ŀ��� ���� ť ����
	circularQueue<UnitInfo> commandSenter(totalQueueCnt);

	int strokeKey = -1;




	while (true)
	{



		//���� �ð� ����
		current_tick = clock();
		currentSec_sec = current_tick / CLOCKS_PER_SEC;


		//Űó��
		if (_kbhit())
		{
			strokeKey = getc(stdin);

			//���� ����
			if (strokeKey >= '0' && strokeKey <= '0'+ totalUnitCnt )
			{
				//�Է� Ű ����ȭ
				static int ikey;
				ikey = strokeKey - '0';

				//���� ���� ���� �� �ʱ�ȭ
				UnitInfo * newUnit = new UnitInfo();
				newUnit->hp = units[ikey].hp;
				strcpy_s(newUnit->name, units[ikey].name);
				newUnit->creationTime = units[ikey].creationTime;

				
				//ť�� �ִ´�
				commandSenter.Enqueue(newUnit, currentSec_sec);
			}

			

			//����
			else if (strokeKey == 'x')
			{
				break;
			}
		}


		//ť�� �� �ð�
		long long inputTime;
		//�ش� ���� ������ �ʿ��� �ð�
		long long unitCreationTime;
		
		//peek Unit 
		UnitInfo peekUnit;
		int qIndex = 0;
		qIndex = 0;

		//����
		//���� �Ϸ� �� ���
		while (commandSenter.PeekTimeByPos(&inputTime, qIndex))
		{
			commandSenter.PeekTimeByPos(&inputTime, qIndex);
			commandSenter.PeekDataByPos(&peekUnit, qIndex);
			unitCreationTime = peekUnit.creationTime;

			int fercent = ((currentSec_sec - inputTime) / unitCreationTime) * 100;

			if (fercent >= 100)
			{
				commandSenter.Dequeue(&peekUnit, qIndex);
				cout << "���� ����:" << peekUnit.name << " " << peekUnit.hp << endl;
			}

			qIndex++;			
		}

		//���
			DisplayScreen(&commandSenter);
		

		//Ÿ�̸�			
			Sleep(1000);

	}

}



void DisplayScreen(circularQueue<UnitInfo> * commandSenter)
{

	//ȭ�� �����
	system("cls");

	cout << "[1~ 9: ���� �� ���� ����Ű / x : ���� ]" << endl << endl;
	cout << "-- Control Tower Unit Create --" << endl;
	for (int i = 0; i < totalQueueCnt; i++)
	{
		cout << "|--------|";

	}
	cout << endl;

	UnitInfo circuitUnit;

	//�̸� ���
	for (int i = 0; i < totalQueueCnt; i++)
	{
		if (commandSenter->PeekDataByPos(&circuitUnit, i))
		{
			cout << "|";
			printf("%-8s", circuitUnit.name);
			cout << "|";
		}
	}
	cout << endl;

	//hp ���
	for (int i = 0; i < totalQueueCnt; i++)
	{
		if (commandSenter->PeekDataByPos(&circuitUnit, i))
		{
			cout << "|";
			printf("hp:%-5d", circuitUnit.hp);
			cout << "|";
		}
	}
	cout << endl;



	int fercent = -1;
	//���� % ���
	for (int i = 0; i < totalQueueCnt; i++)
	{
		long long inputTime = -1;
		if (commandSenter->PeekDataByPos(&circuitUnit, i))
		{
			commandSenter->PeekTimeByPos(&inputTime, i);
			fercent = ((currentSec_sec- inputTime) / circuitUnit.creationTime) * 100 ;
			printf("l%5d(%%)", fercent);
			cout << "|";
		}
	}
	cout << endl;



	for (int i = 0; i < totalQueueCnt; i++)
	{
		cout << "|--------|";

	}
	cout << endl;
}

