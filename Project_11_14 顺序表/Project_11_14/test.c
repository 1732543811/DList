#include "Seqlist.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

//顺序表初始化
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


//在顺序表尾部插入元素data
void SeqListPushBack(PSeqList ps, DataType data){
	ps->_pData[ps->_size++] = data;
	

}

//删除顺序表中的最后一个元素
void SeqListPopBack(PSeqList ps){
	assert(ps);
	if (ps->_size)
		ps->_size--;
}
//在顺序表的头部插入元素data
void SeqListPushFront(PSeqList ps, DataType data){
	assert(ps);
	if (0 == ps->_size)
		return;
	//现在要将顺序表中的有效元素向前搬移一位
	for ( int i = 0; i <ps->_size-1; i++)
	{
		ps->_pData[i] = ps->_pData[i + 1];

	} 
	ps->_size--;
}
//在顺序表的pos位置插入元素data
void SeqListInsert(PSeqList ps, int pos, DataType data){
	assert(ps);
	if (pos<0 || pos>ps->_size){
		printf("插入位置有误，无法插入");
		return ;
	}
	//插入位置之后的元素整体向后搬移一个位置
	for ( int i=pos+1; i < ps->_size ; i++)
	{
		ps->_pData[i + 1] = ps->_pData[i];
	}
	//插入元素
	ps->_pData[pos] = data;
	ps->_size++;

}
//删除顺序表中pos位置的元素
void SeqListErase(PSeqList ps, int pos){
	assert(ps);
	if (pos<0 || pos>ps->_size){
		printf("位置有误，无法插入");
		return;
	}
	for (int i=pos+1 ; i < ps->_size; i++)
	{
		ps->_pData[i-1] = ps->_pData[i];

	}
	ps->_size--;
}
//在顺序表中找出data元素第一次出现的位置
int SeqListFind(PSeqList ps, DataType data){
	assert(ps);
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_pData[i]==data)
		{
			
			return i;
		}
		
		
	
	}
	return -1;//没找到就返回-1
}
//删除顺序表中值为data的元素
void SeqListRemove(PSeqList ps, DataType data){
	int pos = SeqListFind(ps, data);
	SeqListErase(ps, pos);
}
//获取顺序表中有效元素的个数
int SeqListSize(PSeqList ps){
	assert(ps);
	return ps->_size;

}
//获取顺序表的容量
// 获取顺序表的容量
int SeqListCapacity(PSeqList ps){
	assert(ps);
	return ps->_capacity;
}
//检测容量
//1.申请新空间；
//2.拷贝元素
//3.释放旧空间；
void CheckCapacity(PSeqList ps){
	assert(ps);
	if (ps->_size==ps->_capacity)
	{
		int newCapacity = ps->_capacity * 2;
		DataType* pNew = (DataType*)malloc(sizeof(DataType)*newCapacity);
		if (NULL==pNew)
		{
			printf("申请失败，内存不足");
				exit(1);
		}
		memcpy(pNew, ps->_pData, sizeof(ps->_pData));
		free(ps->_pData);


	}

}



//获取顺序表中第一个元素
// 获取顺序表中第一个元素
DataType SeqListFront(PSeqList ps){
	assert(ps);
	return ps->_pData[0];

}

// 获取顺序表中最后一个元素
DataType SeqListBack(PSeqList ps){
	assert(ps);
	return ps->_pData[ps->_size-1];

}
//清空顺序表中的有效元素的个数

void SeqListClear(PSeqList ps){
	assert(ps);
	ps->_size = 0;
}
//销毁顺序表
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

	//或者下面的办法
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

	//在顺序表中头插0
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

//冒泡排序
void BubbleSort(PSeqList ps)
{
	assert(ps);
	//外部循环控制冒泡的次数，内部循环控制具体冒泡方式
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