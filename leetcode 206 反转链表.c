#include<stdio.h>

/*leetcode 206 反转链表
反转一个单链表。
示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
*/

/*
一：头插法(相当于反向指)
创建新链表 prev = NULL;(头节点)
cur 指向第一个节点
next 为cur的后驱

next = cur->next;
cur->next = prev;
prev = cur;
cur = next;
*/
struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL){
		return head;
	}
	//创建一个新链表
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	while (cur){
		struct ListNode* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}
/*
二：三指针法
prev = NULL;
cur = head;
next = head->next;
*/
struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL){
		return head;
	}
	//
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	struct ListNode* next = head->next;
	while (cur){
		cur->next = prev;
		prev = cur;
		cur = next;
		if (next){
			next = next->next;
		}
	}
	return prev;
}
