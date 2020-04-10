/*leetcode 160 相交链表
编写一个程序，找到两个单链表相交的起始节点。
如下面的两个链表：
a1->a2->c1->c2
b1->b2->c1->c2
在节点 c1 开始相交。
*/
/*
找出较长链表，让他先走与较短链表之差个位置，然后两个链表再同时走，当地址相同时，就是相交节点；
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL || headB == NULL){
		return NULL;
	}
	struct ListNode* A = headA;
	struct ListNode* B = headB;
	int lA, lB;
	lA = lB = 0;
	//找出长度
	while (A){
		lA++;
		A = A->next;
	}
	while (B){
		lB++;
		B = B->next;
	}
	int d = abs(lA - lB);
	if (lA < lB){
		A = headB;
		B = headA;
	}
	else{
		A = headA;
		B = headB;
	}
	//长的先走
	while (d--){
		A = A->next;
	}
	while (A && B){
		//比较地址
		if (A == B){
			return A;
		}
		A = A->next;
		B = B->next;
	}
	return NULL;
}