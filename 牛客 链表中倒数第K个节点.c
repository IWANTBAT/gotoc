#include<stdio.h>

/*
牛客 链表中倒数第K个节点
*/
/*
一：（1）遍历链表，找出节点总数n
（2）返回第n-(n-k)个节点
二：快慢指针
（1）让第一个指针（快指针）先走K步
（2）然后让快指针和慢指针同时走，当快指针为空时，慢指针指向的就是倒数第K个节点
*/
struct ListNode* findktotail(struct ListNode* head, unsigned int k){
	if (head == NULL){
		return NULL;
	}
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	//让快指针先走K步
	while (k--){
		//fast = fast->next;写在此处会多走一步
		if (fast == NULL){
			return fast;
		}
		fast = fast->next;
	}
	//让slow和fast同时走
	while (fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

