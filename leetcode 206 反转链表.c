#include<stdio.h>

/*leetcode 206 ��ת����
��תһ��������
ʾ��:
����: 1->2->3->4->5->NULL
���: 5->4->3->2->1->NULL
*/

/*
һ��ͷ�巨(�൱�ڷ���ָ)
���������� prev = NULL;(ͷ�ڵ�)
cur ָ���һ���ڵ�
next Ϊcur�ĺ���

next = cur->next;
cur->next = prev;
prev = cur;
cur = next;
*/
struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL){
		return head;
	}
	//����һ��������
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
������ָ�뷨
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
