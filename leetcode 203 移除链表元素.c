#include<stdio.h>

/*leetcode 203 移除链表元素
删除链表中等于给定值 val 的所有节点。
示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

struct ListNode {
	int val;
	struct ListNode *next;

};
struct ListNode* removeElements(struct ListNode* head, int val){
	if (head == NULL){
		return head;
	}
	struct ListNode* prev = NULL;//前驱
	struct ListNode* cur = head;//判断节点
	while (cur){
		struct ListNode* next = cur->next;//后驱
		if (cur->val == val){//判断
			if (cur == head){//判断是否为头节点
				head = next;//更新头节点
			}
			else{
				prev->next = next;
			}
			free(cur);//释放节点
			cur = next;
		}
		else{//后移
			prev = cur;
			cur = next;
		}
	}
	return head;
}
