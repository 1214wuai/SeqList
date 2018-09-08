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

void PopBack(PSeqList* pSeq)//尾部删除
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
		pSeq->_size--;//不用赋值0，数据类型不为int类型时，不能赋值0，_size才是管理结构体的
	}
}

void PushFront(PSeqList* pSeq, DataType data)//头部插入
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

void PopFront(PSeqList* pSeq)//头部删除
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

void Insert(PSeqList* pSeq, size_t pos, DataType data)//pos为size_t，end为int类型，比较时end>=pos，有符号向无符号转换，end第一个符号位会变成一个很大的数，以至于越界
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
		int end = pSeq->_size-1;//-1与没有-1，重点
		while (end >= (int)pos)//类型提升，范围小的会向范围大的转,所以要强转，没强转就越界了,而且在小标为0时才会产生错误
		{
			pSeq->a[end + 1] = pSeq->a[end];
			--end;
		}
		pSeq->a[pos] = data;
		pSeq->_size++;
	}
}

void Erase(PSeqList* pSeq, size_t pos)//指定位置删除
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

void Remove(PSeqList* pSeq, DataType data)//指定元素删除
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

void RemoveAll(PSeqList* pSeq, DataType data)//删除所有指定元素
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

int Size(PSeqList* pSeq)//返回顺序表的大小
{
	assert(pSeq != NULL);
	int sz = sizeof(DataType)*pSeq->_size;
	return sz;
}

int Empty(PSeqList* pSeq)//判断顺序表是否为空
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

void BubbleSort(PSeqList* pSeq)//冒泡排序
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

void SelectSort(PSeqList* pSeq)//选择排序
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

void SelectSortOP(PSeqList* pSeq)//选择排序优化
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

int BinarySearch(PSeqList* pSeq, DataType data)//二分查找
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