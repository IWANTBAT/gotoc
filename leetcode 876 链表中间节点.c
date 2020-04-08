#include<stdio.h>

/*leetcode 876 �����м�ڵ�
����һ������ͷ��� head �ķǿյ���������������м��㡣
����������м��㣬�򷵻صڶ����м��㡣
���룺[1,2,3,4,5]
��������б��еĽ�� 3 (���л���ʽ��[3,4,5])
���صĽ��ֵΪ 3 �� (����ϵͳ�Ըý�����л������� [3,4,5])��
ע�⣬���Ƿ�����һ�� ListNode ���͵Ķ��� ans��������
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, �Լ� ans.next.next.next = NULL.
*/


//һ�������ҳ��м�ڵ�
struct ListNode* middleNode(struct ListNode* head){
	if (head == NULL){
		return head;
	}
	int count = 0;
	struct ListNode* cur = head;
	while (cur){
		count++;
		cur = cur->next;
	}
	int mid = count / 2 + 1;
	int idx = 1;
	cur = head;
	while (cur){
		if (mid == idx){
			return cur;
		}
		cur = cur->next;
		idx++;
	}
	return NULL;
}

//��������ָ��
struct ListNode* middleNode(struct ListNode* head){
	if (head == NULL){
		return head;
	}
	//����ָ��
	struct ListNode* slow = head;//��ָ�룬һ����һ��
	struct ListNode* fast = head;//��ָ�룬һ��������
	while (fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;//������ָ����Ϊ�м�ڵ�
}

