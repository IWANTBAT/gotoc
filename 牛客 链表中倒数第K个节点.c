#include<stdio.h>

/*
ţ�� �����е�����K���ڵ�
*/
/*
һ����1�����������ҳ��ڵ�����n
��2�����ص�n-(n-k)���ڵ�
��������ָ��
��1���õ�һ��ָ�루��ָ�룩����K��
��2��Ȼ���ÿ�ָ�����ָ��ͬʱ�ߣ�����ָ��Ϊ��ʱ����ָ��ָ��ľ��ǵ�����K���ڵ�
*/
struct ListNode* findktotail(struct ListNode* head, unsigned int k){
	if (head == NULL){
		return NULL;
	}
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	//�ÿ�ָ������K��
	while (k--){
		//fast = fast->next;д�ڴ˴������һ��
		if (fast == NULL){
			return fast;
		}
		fast = fast->next;
	}
	//��slow��fastͬʱ��
	while (fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

