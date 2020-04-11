/*leetcode 141 环形链表
给定一个链表，判断链表中是否有环。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
*/
/*
快慢指针：slow每次走一步；fast每次走两步；
如果slow和fast相遇，说明有环
为什么fast每次走两步，而不是三步或四步？
答：假设有环，fast每次比slow多走一步，相当于每次循环差距减一，即如果相差100步，那么只要循环100次就一定会相遇；
如果三步或四步或者更多，有可能会错过相遇点，极端情况下，即使有环也不会相遇；
*/
bool hasCycle(struct ListNode *head) {
	if (head == NULL){
		return false;
	}
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast){
			return true;
		}
	}
	return false;
}

/*如果有环，如何求环的节点个数？
答：从相遇点继续走，当再次走到相遇点时，所经过的节点个数就是环的长度；
*/