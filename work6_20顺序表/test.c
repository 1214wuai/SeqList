#include"shunxu.h"
PSeqList s;

void test1()
{
	InitSetList(&s);//��ʼ��
	 PushBack(&s, 1);
	 PushBack(&s, 2);
	 PushBack(&s, 3);
	 PushBack(&s, 4);
	 PrintSetList(&s);//��ӡβ������
	 PushFront(&s, 4);
	 PushFront(&s, 3);
	 PushFront(&s, 2);
	 PushFront(&s, 1);
	 PrintSetList(&s);//��ӡͷ������
	 PopBack(&s);
	 PopBack(&s);
	 PrintSetList(&s);//��ӡβ��ɾ��
	 PopFront(&s);
	 PopFront(&s);
	 PrintSetList(&s);//��ӡͷ��ɾ��

	 Find(&s, 2);//����ָ��Ԫ��

	 PushFront(&s, 1);
	 PushFront(&s, 2);
	 PushFront(&s, 3);
	 PushFront(&s, 4);
	 PushFront(&s, 5);

	 PrintSetList(&s);
	

	 Insert(&s, 0, 6);//ָ��λ�ò���
	 PrintSetList(&s);
	 Erase(&s, 0);//ָ��λ��ɾ��
	 PrintSetList(&s);
	 Remove(&s, 3);//ָ��Ԫ��ɾ��
	 PrintSetList(&s);
	 RemoveAll(&s, 1);//ɾ������ָ��Ԫ��
	 PrintSetList(&s);

	 int sz = Size(&s);
	 printf("˳���Ĵ�Сsz = %d\n", sz);

	 int ret = Empty(&s);
	 if (ret != 0)
	 {
		 printf("˳���Ϊ��\n");
	 }
	 else
	 {
		 printf("˳���Ϊ��\n");
	 }

	 //BubbleSort(&s);//ð������
	 PrintSetList(&s);

	 SelectSort(&s);//ѡ������
	 PrintSetList(&s);

	 SelectSortOP(&s);//ѡ�������Ż�
	 PrintSetList(&s);

	 int ret2 = BinarySearch(&s, 5);
	 if (ret != -1)
	 {
		 printf("%d\n", ret2);
	 }
	 else
		 printf("û���ҵ�\n");
}
void test2()
{
	InitSetList(&s);//��ʼ��
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
		printf("û���ҵ�\n");

}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}