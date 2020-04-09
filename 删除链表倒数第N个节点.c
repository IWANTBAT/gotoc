#include<stdio.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	if (head == NULL || head->next == NULL) {
		return NULL;
	}
	struct ListNode* p1 = head; //��ָ��
	struct ListNode* p2 = head; //��ָ��
	struct ListNode* pre = NULL; //ָ��ɾ���ڵ��ǰһ���ڵ�ָ��

	int i = 0;
	while (i < n) {
		p2 = p2->next;  //��ָ������n��
		++i;
	}
	/* �ҵ���ɾ���ڵ�p1������ǰһ���ڵ�pre */
	while (p2) {
		pre = p1;
		p1 = p1->next;
		p2 = p2->next;
	}
	if (pre) {
		// pre�ڵ����
		pre->next = p1->next;
		free(p1);
		p1 = NULL;
	}
	else {
		// pre�ڵ㲻���ڣ���ɾ��������n���ڵ���ͷ�ڵ�
		head = p1->next;
		free(p1);
		p1 = NULL;
	}
	return head;
}

