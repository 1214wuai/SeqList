#ifndef __SHUNXU_H__
#define __SHUNXU_H__
#include<stdio.h>
#include<assert.h>
#include<string.h>


typedef int DataType;
#define N 10
typedef struct SeqLIst
{
	DataType a[N];
	size_t _size;
}PSeqList;

//增删查改

void InitSetList(PSeqList* pSeq);
void PrintSetList(PSeqList* pSeq);
void PushBack(PSeqList* pSeq, DataType data);//尾部插入
void PopBack(PSeqList* pSeq);//尾部删除
void PushFront(PSeqList* pSeq, DataType data);//头部插入
void PopFront(PSeqList* pSeq);//头部删除
int Find(PSeqList* pSeq, DataType data);//查找指定元素
void Insert(PSeqList* pSeq, size_t pos, DataType data);//指定位置插入
void Erase(PSeqList* pSeq, size_t pos);//指定位置删除
void Remove(PSeqList* pSeq, DataType data);//指定元素删除
void RemoveAll(PSeqList* pSeq, DataType data);//删除所有指定元素
int Size(PSeqList* pSeq);//顺序表的大小
int Empty(PSeqList* pSeq);//判断顺序表是否为空
void BubbleSort(PSeqList* pSeq);//冒泡排序
void SelectSort(PSeqList* pSeq);//选择排序
void SelectSortOP(PSeqList* pSeq);//选择排序
int BinarySearch(PSeqList* pSeq, DataType data);//二分查找
int BinarySearch_R(PSeqList* pSeq, int left, int right, DataType data);//二分查找递归方法
#endif //__SHUNXU_H__
