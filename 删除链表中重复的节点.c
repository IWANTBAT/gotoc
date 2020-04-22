
/*牛客 删除链表中重复的节点
在一个排序链表中，存在重复的节点，请删除重复节点，重复节点不保留，返回头指针；
例如：1—>2->3->3->4->4->5删除后为：1->2->5
*/
struct ListNode* delete(struct ListNode* head){
	if (head == NULL){
		return NULL;
	}
	struct ListNode* prev, *cur, *next;
	prev = NULL;
	cur = head;
	next = cur->next;
	while (next){
		if (cur->val == next->val){//整个相同节点区间删除（因为是有序的）
			next = next->next;
			while (next && next->val == cur->val){
				next = next->next;
			}
			if (prev == NULL){
				head = next;
			}
			else{
				prev->next = next;
			}
			while (cur != next){
				struct ListNode* temp = cur;
				free(cur);
				cur = temp;
			}
			cur = next;
			if (next){
				next = next->next;
			}
		}
		else{
			prev = cur;
			cur = next;
			next = next->next;
		}

	}
	return head;

}