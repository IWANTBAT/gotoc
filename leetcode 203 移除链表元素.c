#include<stdio.h>

/*leetcode 203 �Ƴ�����Ԫ��
ɾ�������е��ڸ���ֵ val �����нڵ㡣
ʾ��:
����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5
*/

struct ListNode {
	int val;
	struct ListNode *next;

};
struct ListNode* removeElements(struct ListNode* head, int val){
	if (head == NULL){
		return head;
	}
	struct ListNode* prev = NULL;//ǰ��
	struct ListNode* cur = head;//�жϽڵ�
	while (cur){
		struct ListNode* next = cur->next;//����
		if (cur->val == val){//�ж�
			if (cur == head){//�ж��Ƿ�Ϊͷ�ڵ�
				head = next;//����ͷ�ڵ�
			}
			else{
				prev->next = next;
			}
			free(cur);//�ͷŽڵ�
			cur = next;
		}
		else{//����
			prev = cur;
			cur = next;
		}
	}
	return head;
}
