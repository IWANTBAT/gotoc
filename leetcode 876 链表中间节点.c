#include<stdio.h>

/*leetcode 876 链表中间节点
给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。
输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
*/


//一：遍历找出中间节点
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

//二：快慢指针
struct ListNode* middleNode(struct ListNode* head){
	if (head == NULL){
		return head;
	}
	//快慢指针
	struct ListNode* slow = head;//慢指针，一次走一步
	struct ListNode* fast = head;//快指针，一次走两步
	while (fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;//最终慢指针则为中间节点
}

