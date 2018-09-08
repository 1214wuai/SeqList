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

//��ɾ���

void InitSetList(PSeqList* pSeq);
void PrintSetList(PSeqList* pSeq);
void PushBack(PSeqList* pSeq, DataType data);//β������
void PopBack(PSeqList* pSeq);//β��ɾ��
void PushFront(PSeqList* pSeq, DataType data);//ͷ������
void PopFront(PSeqList* pSeq);//ͷ��ɾ��
int Find(PSeqList* pSeq, DataType data);//����ָ��Ԫ��
void Insert(PSeqList* pSeq, size_t pos, DataType data);//ָ��λ�ò���
void Erase(PSeqList* pSeq, size_t pos);//ָ��λ��ɾ��
void Remove(PSeqList* pSeq, DataType data);//ָ��Ԫ��ɾ��
void RemoveAll(PSeqList* pSeq, DataType data);//ɾ������ָ��Ԫ��
int Size(PSeqList* pSeq);//˳���Ĵ�С
int Empty(PSeqList* pSeq);//�ж�˳����Ƿ�Ϊ��
void BubbleSort(PSeqList* pSeq);//ð������
void SelectSort(PSeqList* pSeq);//ѡ������
void SelectSortOP(PSeqList* pSeq);//ѡ������
int BinarySearch(PSeqList* pSeq, DataType data);//���ֲ���
int BinarySearch_R(PSeqList* pSeq, int left, int right, DataType data);//���ֲ��ҵݹ鷽��
#endif //__SHUNXU_H__
