/*leetcode 21 合并两个有序链表
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	//特殊情况
	if (l1 == NULL){
		return l2;
	}
	if (l2 == NULL){
		return l1;
	}
	struct ListNode* nh;
	struct ListNode* nt;
	//确定头节点
	if (l1->val > l2->val){
		nh = nt = l2;
		l2 = l2->next;
	}
	else{
		nh = nt = l1;
		l1 = l1->next;
	}
	//合并：两个链表都不为空
	while (l1 && l2){
		if (l1->val < l2->val){
			nt->next = l1;
			l1 = l1->next;
		}
		else{
			nt->next = l2;
			l2 = l2->next;
		}
		nt = nt->next;
	}
	//合并剩余节点
	if (l1){
		nt->next = l1;
	}
	if (l2){
		nt->next = l2;
	}
	return nh;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	//特殊情况
	if (l1 == NULL){
		return l2;
	}
	if (l2 == NULL){
		return l1;
	}
	struct ListNode* nh;
	struct ListNode* nt;
	//创建一个新表头（表头指向头节点）
	nh = nt = (struct ListNode*)malloc(sizeof(struct ListNode));
	//合并：两个链表都不为空
	while (l1 && l2){
		if (l1->val < l2->val){
			nt->next = l1;
			l1 = l1->next;
		}
		else{
			nt->next = l2;
			l2 = l2->next;
		}
		nt = nt->next;
	}
	//合并剩余节点
	if (l1){
		nt->next = l1;
	}
	if (l2){
		nt->next = l2;
	}
	struct ListNode* head = nh->next;
	return head;
	free(nh);
	free(nt);
}