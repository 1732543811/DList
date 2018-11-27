#pragma once

typedef int DataType;

// 动态顺序表的结构
typedef struct SeqList
{
	DataType* _pData;  // 空间的首地址
	int _capacity;     // 空间的总大小
	int _size;         // 有效元素的个数
}SeqList, *PSeqList;


// 初始化顺序表
void SeqListInit(PSeqList ps, int capacity);

// 在顺序表尾部插入元素data
void SeqListPushBack(PSeqList ps, DataType data);

// 删除顺序表中最后的一个元素
void SeqListPopBack(PSeqList ps);
// 在顺序表的头部插入元素data
void SeqListPushFront(PSeqList ps, DataType data);

// 删除顺序表的头部元素
void SeqListPopFront(PSeqList ps);

// 在顺序表的pos位置插入元素data
void SeqListInsert(PSeqList ps, int pos, DataType data);

// 删除顺序表中pos位置上的元素
void SeqListErase(PSeqList ps, int pos);

// 在顺序表中找data元素第一次出现的位置
int SeqListFind(PSeqList ps, DataType data);

// 删除顺序表中值为data的元素
void SeqListRemove(PSeqList ps, DataType data);

// 获取顺序表中有效元素的个数
int SeqListSize(PSeqList ps);

// 获取顺序表的容量
int SeqListCapacity(PSeqList ps);

// 获取顺序表中第一个元素
DataType SeqListFront(PSeqList ps);

// 获取顺序表中最后一个元素
DataType SeqListBack(PSeqList ps);

// 清空顺序表中有效元素的个数
void SeqListClear(PSeqList ps);

// 销毁顺序表
void SeqListDestroy(PSeqList ps);

// 检测容量
void CheckCapacity(PSeqList ps);

// 删除顺序表中所有值为data的元素
void SeqListRemoveAll(PSeqList ps, DataType data);

// 用冒泡排序的方式对顺序表中的元素进行排序
void BubbleSort(PSeqList ps);

//////////////////////////////////////////////////////
void TestSeqList();
