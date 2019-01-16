#pragma once

#include <iostream>

using namespace std;


template<typename DATA_TYPE>
class ELEMENT_Q
{
private:
	//���� �ð�
	long long inputTime;

	//���� ���� ��ȣ
	long sequence;

	//���� ������
	DATA_TYPE *data;

public:

	//������
	ELEMENT_Q(long long facTime, long facSeq, DATA_TYPE *inData)
	{
		inputTime = facTime;
		sequence = facSeq;
		data = inData;
	}

	long long GetInputTime()
	{
		return inputTime;
	}

	long GetSequence()
	{
		return sequence;
	}

	DATA_TYPE* GetData()
	{
		return data;
	}

};


template <typename DATA_TYPE>
class circularQueue
{
private:
	int front;
	int rear;

	//ť �迭 ���� ������
	ELEMENT_Q<DATA_TYPE> **elementArr;
	
	//�� ť ũ��
	long totalSz;

	//���� ��� ����
	long nowCnt;

	//�� ���� ����
	long totalSequence;


public:
	//������ 
	circularQueue(long sz)
	{
		front = 0;
		rear = 0;

		totalSz = sz;

		//���� �迭 ���� �Ҵ�
		elementArr = (ELEMENT_Q<DATA_TYPE>**)malloc(sizeof(ELEMENT_Q<DATA_TYPE>*) *sz);
		

		if (elementArr == NULL)
			cout<<"error";

		totalSequence = 0;
	}


	//�� ���� üũ
	bool IsEmpty()
	{
		if (nowCnt == 0)
			return true;
		else
			return false;
	}


	//���� �� ���� üũ
	bool IsFull()
	{
		if (nowCnt == totalSz)
			return true;
		else
			return false;
	}


	//���� ������ �ε������� ���� ������ �ε��� ��ȯ
		//���� ���� ���� front, rear �� ����
	inline long GetNextIndex(int *nowPosition)
	{
		return ( (*nowPosition)++) % totalSz;
	}


	//���� ������ �ε������� +moveInterval �ε��� ��ȯ
		//���� ���� ���� front, rear �� ����
	inline long GetNextIndex(int nowPosition, int moveInterval)
	{
		return (nowPosition + moveInterval) % totalSz;
	}


	//����
	bool Enqueue(DATA_TYPE *inData, long long inputTime)
	{
		//���� �� ��� 
			//���� �Ұ�
		if (IsFull())
			return false;

		//���� ��� ����
		//static ELEMENT_Q<DATA_TYPE> *NEW_ELEMENT = new ELEMENT_Q<DATA_TYPE>(inputTime,  totalSequence++, inData);

	

		//ť�� ����
		elementArr[ GetNextIndex(&rear) ] = new ELEMENT_Q<DATA_TYPE>(inputTime, totalSequence++, inData);

		//���� ��� ���� ����
		nowCnt++;
		
		return true;
	}

	//����
	bool Dequeue(DATA_TYPE *outData)
	{
		if (IsEmpty())
		{
			return false;
		}

		//���� ��� ���� ����
		nowCnt--;

		DATA_TYPE *returnData = elementArr[GetNextIndex(&front)]->GetData();
		*outData = *returnData;

		return true;
	}


	//����
	bool Dequeue(DATA_TYPE *outData, int index)
	{
		if (IsEmpty())
		{
			return false;
		}

		//���� ��� ���� ����
		nowCnt--;

		DATA_TYPE *returnData = elementArr[GetNextIndex(&front), index]->GetData();


		//���߿� ó�� �� ��!!
		//
		//int k = front + index;
		//int j = k %totalQueueCnt;

		////���� �� ��ŭ ��ܾ� �Ѵ�
		//for (int i = k; i < totalQueueCnt; )
		//{
		//	elementArr[i % totalQueueCnt] = elementArr[GetNextIndex(&k)];

		//	i = (i++) & totalQueueCnt;
		//}


		*outData = *returnData;


		return true;
	}


	
	bool PeekDataByPos(DATA_TYPE *outData, long pos)
	{
		if (pos > nowCnt-1)
		{
			return false;
		}


		DATA_TYPE *returnData = elementArr[GetNextIndex(front, pos)]->GetData();
		*outData = *returnData;

		return true;
	}


	bool PeekTimeByPos(long long *outTime, long pos)
	{
		if (pos > nowCnt - 1)
		{
			return false;
		}


		long long returnTime = elementArr[GetNextIndex(front, pos)]->GetInputTime();
		*outTime = returnTime;

		return true;
	}


};