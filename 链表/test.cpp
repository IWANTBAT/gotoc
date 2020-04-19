#include "List.h"
void test()
{
	List lst;
	listInit(&lst);
	listPushFront(&lst, 0);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	printList(&lst);
	listPopBack(&lst);
	printList(&lst);
	listPopBack(&lst);
	printList(&lst);
	listPopBack(&lst);
	printList(&lst);
	listPopBack(&lst);
	printList(&lst);

	listPushFront(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);
	printList(&lst);
	listPopBack(&lst);
	printList(&lst);
	listPopBack(&lst);
	printList(&lst);
	listPopBack(&lst);
	printList(&lst);
	listPopBack(&lst);
	printList(&lst);
	listPopBack(&lst);
	printList(&lst);
	
}

void test2()
{
	List lst;
	listInit(&lst);
	listPushFront(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);
	printList(&lst);

	listPopFront(&lst);
	printList(&lst);
	listPopFront(&lst);
	printList(&lst);
	listPopFront(&lst);
	printList(&lst);
	listPopFront(&lst);
	printList(&lst);
	listPopFront(&lst);
	printList(&lst);

	listPushFront(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);
	printList(&lst);

	listPopFront(&lst);
	printList(&lst);
	listPopFront(&lst);
	printList(&lst);
	listPopFront(&lst);
	printList(&lst);
	listPopFront(&lst);
	printList(&lst);
	listPopFront(&lst);
	printList(&lst);


}

int main()
{
	//test();
	test2();
	return 0;
}