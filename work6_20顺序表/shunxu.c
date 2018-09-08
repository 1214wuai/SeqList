#include"shunxu.h"
void InitSetList(PSeqList* pSeq)
{
	memset(pSeq->a, 0, sizeof(DataType)*N);
	pSeq->_size = 0;
}

void PrintSetList(PSeqList* pSeq)
{
	size_t i = 0;
	for (i = 0; i < pSeq->_size; i++)
	{
		printf("%d ", pSeq->a[i]);
	}
	printf("\n");
}

void PushBack(PSeqList* pSeq, DataType data)
{
	assert(pSeq != NULL);
	if (pSeq->_size >= N)
	{
		printf("SeqList is full");
		return;
	}
	else
	{
		pSeq->a[pSeq->_size++] = data;
		//pSeq->_size++;
	}

}

void PopBack(PSeqList* pSeq)//β��ɾ��
{
	assert(pSeq != NULL);
	if (pSeq->_size == 0)
	{
		printf("SeqList is empty");
		return;
	}
	else
	{
		//pSeq->a[pSeq->_size - 1] = 0;
		pSeq->_size--;//���ø�ֵ0���������Ͳ�Ϊint����ʱ�����ܸ�ֵ0��_size���ǹ���ṹ���
	}
}

void PushFront(PSeqList* pSeq, DataType data)//ͷ������
{
	assert(pSeq != NULL);
	if (pSeq->_size >= N)
	{
		printf("SeqList is full\n");
		return;
	}
	else
	{
		int end = pSeq->_size - 1;
		while (end>=0)
		{
			pSeq->a[end + 1] = pSeq->a[end];
			--end;
		}
		pSeq->a[0] = data;
		pSeq->_size++;
	}
}

void PopFront(PSeqList* pSeq)//ͷ��ɾ��
{
	assert(pSeq != NULL);
	if (pSeq->_size == 0)
	{
		printf("SeqList is empty");
		return;
	}
	else
	{
		int i = 0;
		for (i = 0; i < (int)pSeq->_size - 1; i++)
		{
			pSeq->a[i] = pSeq->a[i+1];
		}
		pSeq->_size--;
	}
}

int Find(PSeqList* pSeq, DataType data)
{
	assert(pSeq != NULL);
	int i = 0;
	for (i = 0; i < pSeq->_size-1; i++)
	{
		if (pSeq->a[i] == data)
		{
			return i;
		}
	}
	return -1;
	
}

void Insert(PSeqList* pSeq, size_t pos, DataType data)//posΪsize_t��endΪint���ͣ��Ƚ�ʱend>=pos���з������޷���ת����end��һ������λ����һ���ܴ������������Խ��
{
	assert(pSeq != NULL);
	assert(pos <= pSeq->_size);
	if (pSeq->_size >= N)
	{
		printf("SeqList is full\n");
		return;
	}
	else
	{
		int end = pSeq->_size-1;//-1��û��-1���ص�
		while (end >= (int)pos)//������������ΧС�Ļ���Χ���ת,����Ҫǿת��ûǿת��Խ����,������С��Ϊ0ʱ�Ż��������
		{
			pSeq->a[end + 1] = pSeq->a[end];
			--end;
		}
		pSeq->a[pos] = data;
		pSeq->_size++;
	}
}

void Erase(PSeqList* pSeq, size_t pos)//ָ��λ��ɾ��
{
	assert(pSeq != NULL);
	assert(pos < pSeq->_size);
	if (pSeq->_size == 0)
	{
		printf("SeqList is empty\n");
	}
	int i = pos;
	for (i = pos; i < pSeq->_size; i++)
	{
		pSeq->a[i] = pSeq->a[i + 1];
	}
	pSeq->_size--;
}

void Remove(PSeqList* pSeq, DataType data)//ָ��Ԫ��ɾ��
{
	assert(pSeq != NULL);
	int ret = Find(pSeq, data);
	if (ret != -1)
	{
		Erase(pSeq, ret);
		/*int i = 0;
		for (i = ret; i < pSeq->_size ; i++)
		{
			pSeq->a[i] = pSeq->a[i + 1];
		}
		pSeq->_size--;*/
	}
}

void RemoveAll(PSeqList* pSeq, DataType data)//ɾ������ָ��Ԫ��
{
	int i = 0;
	int j = 0;
	int x = pSeq->_size;
	assert(pSeq != NULL);
	for (i = 0; i < x ; i++)
	{
		if (pSeq->a[i] != data)
		{
			pSeq->a[j] = pSeq->a[i];
			j++;
		}
		else
		{
			pSeq->_size--;
		}
	}
}

int Size(PSeqList* pSeq)//����˳���Ĵ�С
{
	assert(pSeq != NULL);
	int sz = sizeof(DataType)*pSeq->_size;
	return sz;
}

int Empty(PSeqList* pSeq)//�ж�˳����Ƿ�Ϊ��
{
	assert(pSeq != NULL);
	return pSeq->_size;
}

void Swap(DataType* l, DataType* r)
{
	DataType tmp = *l;
	*l = *r;
	*r = tmp;
}

void BubbleSort(PSeqList* pSeq)//ð������
{
	int i = 0;
	int j = 0;
	assert(pSeq != NULL);
	for(i = 0; i < pSeq->_size-1; i++)
	{
		for (j = 0; j < pSeq->_size - i - 1; j++)
		{
			if (pSeq->a[j] > pSeq->a[j + 1])
				Swap(&pSeq->a[j], &pSeq->a[j + 1]);
		}
	}
}

void SelectSort(PSeqList* pSeq)//ѡ������
{
	int i = 0;
	int j = 0;
	int maxpos = 0;
	assert(pSeq != NULL);
	for (i = 0; i < pSeq->_size - 1; i++)
	{
		maxpos = 0;
		for (j = 0; j < pSeq->_size-i; j++)
		{
			if (pSeq->a[maxpos] < pSeq->a[j])
				maxpos = j;
		}
		if (maxpos != pSeq->_size - i - 1)
		{
			Swap(&pSeq->a[maxpos], &pSeq->a[pSeq->_size - i - 1]);
		}
	}
}

void SelectSortOP(PSeqList* pSeq)//ѡ�������Ż�
{
	int left = 0;
	int right = pSeq->_size - 1;
	assert(pSeq != NULL);
	while (left < right)
	{
		int min = left;
		int max = right;
		int i = left;
		
		while (i < right)
		{
			if (pSeq->a[i] > pSeq->a[max])
				max = i;
			if (pSeq->a[i] < pSeq->a[min])
				min = i;
			i++;
		}
		Swap(&pSeq->a[left], &pSeq->a[min]);
		if (left == max)
			max = min;
		Swap(&pSeq->a[right], &pSeq->a[max]);
		left++;
		right--;
	}
}

int BinarySearch(PSeqList* pSeq, DataType data)//���ֲ���
{
	int left = 0;
	int right = pSeq->_size-1;
	assert(pSeq != NULL);
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (data == pSeq->a[mid])
			return mid;
		else if (data < pSeq->a[mid])
			right = mid - 1;
		else 
			left = mid + 1;
	}
	return -1;
}

int BinarySearch_R(PSeqList* pSeq, int left, int right, DataType data)
{
	assert(pSeq != NULL);
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (data == pSeq->a[mid])
			return mid;
		else if (data < pSeq->a[mid])
			return BinarySearch_R(pSeq, left, mid - 1, data);
		else
			return BinarySearch_R(pSeq, mid + 1, right, data);
	}
	return -1;
}