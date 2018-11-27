#include "Seqlist.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

//˳����ʼ��
void SeqListInit(PSeqList ps, int capacity)
{
	assert(ps);
	ps->_pData = (DataType*)malloc(sizeof(DataType)*capacity);
	if (NULL == ps->_pData){
		exit(1);
	}
	ps->_capacity = capacity; 
	ps->_size = 0;
}


//��˳���β������Ԫ��data
void SeqListPushBack(PSeqList ps, DataType data){
	ps->_pData[ps->_size++] = data;
	

}

//ɾ��˳����е����һ��Ԫ��
void SeqListPopBack(PSeqList ps){
	assert(ps);
	if (ps->_size)
		ps->_size--;
}
//��˳����ͷ������Ԫ��data
void SeqListPushFront(PSeqList ps, DataType data){
	assert(ps);
	if (0 == ps->_size)
		return;
	//����Ҫ��˳����е���ЧԪ����ǰ����һλ
	for ( int i = 0; i <ps->_size-1; i++)
	{
		ps->_pData[i] = ps->_pData[i + 1];

	} 
	ps->_size--;
}
//��˳����posλ�ò���Ԫ��data
void SeqListInsert(PSeqList ps, int pos, DataType data){
	assert(ps);
	if (pos<0 || pos>ps->_size){
		printf("����λ�������޷�����");
		return ;
	}
	//����λ��֮���Ԫ������������һ��λ��
	for ( int i=pos+1; i < ps->_size ; i++)
	{
		ps->_pData[i + 1] = ps->_pData[i];
	}
	//����Ԫ��
	ps->_pData[pos] = data;
	ps->_size++;

}
//ɾ��˳�����posλ�õ�Ԫ��
void SeqListErase(PSeqList ps, int pos){
	assert(ps);
	if (pos<0 || pos>ps->_size){
		printf("λ�������޷�����");
		return;
	}
	for (int i=pos+1 ; i < ps->_size; i++)
	{
		ps->_pData[i-1] = ps->_pData[i];

	}
	ps->_size--;
}
//��˳������ҳ�dataԪ�ص�һ�γ��ֵ�λ��
int SeqListFind(PSeqList ps, DataType data){
	assert(ps);
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_pData[i]==data)
		{
			
			return i;
		}
		
		
	
	}
	return -1;//û�ҵ��ͷ���-1
}
//ɾ��˳�����ֵΪdata��Ԫ��
void SeqListRemove(PSeqList ps, DataType data){
	int pos = SeqListFind(ps, data);
	SeqListErase(ps, pos);
}
//��ȡ˳�������ЧԪ�صĸ���
int SeqListSize(PSeqList ps){
	assert(ps);
	return ps->_size;

}
//��ȡ˳��������
// ��ȡ˳��������
int SeqListCapacity(PSeqList ps){
	assert(ps);
	return ps->_capacity;
}
//�������
//1.�����¿ռ䣻
//2.����Ԫ��
//3.�ͷžɿռ䣻
void CheckCapacity(PSeqList ps){
	assert(ps);
	if (ps->_size==ps->_capacity)
	{
		int newCapacity = ps->_capacity * 2;
		DataType* pNew = (DataType*)malloc(sizeof(DataType)*newCapacity);
		if (NULL==pNew)
		{
			printf("����ʧ�ܣ��ڴ治��");
				exit(1);
		}
		memcpy(pNew, ps->_pData, sizeof(ps->_pData));
		free(ps->_pData);


	}

}



//��ȡ˳����е�һ��Ԫ��
// ��ȡ˳����е�һ��Ԫ��
DataType SeqListFront(PSeqList ps){
	assert(ps);
	return ps->_pData[0];

}

// ��ȡ˳��������һ��Ԫ��
DataType SeqListBack(PSeqList ps){
	assert(ps);
	return ps->_pData[ps->_size-1];

}
//���˳����е���ЧԪ�صĸ���

void SeqListClear(PSeqList ps){
	assert(ps);
	ps->_size = 0;
}
//����˳���
void SeqListDestroy(PSeqList ps){
	assert(ps);
	if (ps->_pData){
		ps->_capacity = 0;
		ps->_size = 0;
	}
}
void SeqListRemoveAll(PSeqList ps, DataType data){
	int count = 0;
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_pData[i] != data)
			ps->_pData[i - count] = ps->_pData[i];
		else
			count++;

	}

	ps->_size += count;

	//��������İ취
	int pos = -1;
	while (-1 != (pos = SeqListFind(ps, data))){
		SeqListErase(ps, pos);
	}
}
void PrintSeqList(PSeqList ps){
	assert(ps);
	for ( int i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_pData[i]);
	}
	printf("\n");
}



void TestSeqList1(){
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);

	printf("%d\n", SeqListSize);
	PrintSeqList(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	printf("%d\n", SeqListSize);
	PrintSeqList(&s);

	//��˳�����ͷ��0
	SeqListPushBack(&s, 0);
	PrintSeqList(&s);
}
void TestSeqList2(){
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	PrintSeqList(&s);

	printf("%d\n", SeqListSize);
	PrintSeqList(&s);

	SeqListInsert(&s, 3, 11);
	PrintSeqList(&s);
	
}

void TestSeqList3(){
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 6);
	PrintSeqList(&s);
	//SeqListRemoveAll(&s, 2);
	BubbleSort(&s);

    PrintSeqList(&s);
}

//ð������
void BubbleSort(PSeqList ps)
{
	assert(ps);
	//�ⲿѭ������ð�ݵĴ������ڲ�ѭ�����ƾ���ð�ݷ�ʽ
	for (int i = 0; i < ps->_size - 1; i++)
	{
		for (int j = 0; j <ps->_size-1-i ; j++)
		{
			// 1 5 3 6 2
			if (ps->_pData[j] >ps->_pData[j+1])
			{
				DataType temp = ps->_pData[j];
				ps->_pData[j] = ps->_pData[j + 1];
				ps->_pData[j + 1] = temp;
			}
		}
	}


}

int main(){
	TestSeqList3();
	system("pause");
	
	return 0;
}