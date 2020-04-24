#include"ListNode.h"

void test(){
	List lst;listInit(&lst);
	listPushFront(&lst, 5);
	listPushFront(&lst, 4);
	listPushFront(&lst, 3);
	listPushFront(&lst, 2);
	listPushFront(&lst, 1);
	
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);
	
	listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);

	listPopFront(&lst);
	PrintList(&lst);
}

int main()
{
	test();
	return 0;
}