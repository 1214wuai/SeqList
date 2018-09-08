#include"shunxu.h"
PSeqList s;

void test1()
{
	InitSetList(&s);//初始化
	 PushBack(&s, 1);
	 PushBack(&s, 2);
	 PushBack(&s, 3);
	 PushBack(&s, 4);
	 PrintSetList(&s);//打印尾部插入
	 PushFront(&s, 4);
	 PushFront(&s, 3);
	 PushFront(&s, 2);
	 PushFront(&s, 1);
	 PrintSetList(&s);//打印头部插入
	 PopBack(&s);
	 PopBack(&s);
	 PrintSetList(&s);//打印尾部删除
	 PopFront(&s);
	 PopFront(&s);
	 PrintSetList(&s);//打印头部删除

	 Find(&s, 2);//查找指定元素

	 PushFront(&s, 1);
	 PushFront(&s, 2);
	 PushFront(&s, 3);
	 PushFront(&s, 4);
	 PushFront(&s, 5);

	 PrintSetList(&s);
	

	 Insert(&s, 0, 6);//指定位置插入
	 PrintSetList(&s);
	 Erase(&s, 0);//指定位置删除
	 PrintSetList(&s);
	 Remove(&s, 3);//指定元素删除
	 PrintSetList(&s);
	 RemoveAll(&s, 1);//删除所有指定元素
	 PrintSetList(&s);

	 int sz = Size(&s);
	 printf("顺序表的大小sz = %d\n", sz);

	 int ret = Empty(&s);
	 if (ret != 0)
	 {
		 printf("顺序表不为空\n");
	 }
	 else
	 {
		 printf("顺序表为空\n");
	 }

	 //BubbleSort(&s);//冒泡排序
	 PrintSetList(&s);

	 SelectSort(&s);//选择排序
	 PrintSetList(&s);

	 SelectSortOP(&s);//选择排序优化
	 PrintSetList(&s);

	 int ret2 = BinarySearch(&s, 5);
	 if (ret != -1)
	 {
		 printf("%d\n", ret2);
	 }
	 else
		 printf("没有找到\n");
}
void test2()
{
	InitSetList(&s);//初始化
	PushBack(&s, 1);
	PushBack(&s, 2);
	PushBack(&s, 3);
	PushBack(&s, 4);
	PushBack(&s, 5);
	PushBack(&s, 6);
	PushBack(&s, 7);
	PushBack(&s, 8);
	PushBack(&s, 9);
	PushBack(&s, 10);
	int ret = BinarySearch_R(&s, 0, s._size - 1, 5);
	if (ret != -1)
	{
		printf("%d\n", ret);
	}
	else
		printf("没有找到\n");

}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}