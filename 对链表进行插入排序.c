/*leetcode 147 对链表进行插入排序
插入排序算法：
插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止
*/
struct ListNode {
	int val;
	struct ListNode *next;

};

struct ListNode* insertionSortList(struct ListNode* head){
	if (head == NULL){
		return NULL;
	}
	struct ListNode* header, *prev, *node, *cur;
	header = (struct ListNode*)malloc(sizeof(struct ListNode));
	header->next = head;
	prev = head;
	cur = head->next;
	while (cur){
		if (cur->val < prev->val){
			//从头开始找第一个大于cur的节点
			node = header;
			while (node->next && node->next->val <= cur->val){
				node = node->next;
			}
			struct ListNode* next = node->next;
			prev->next = cur->next;
			cur->next = next;
			node->next = cur;
			cur = prev->next;
		}
		else{
			prev = cur;
			cur = cur->next;
		}
	}
	return header->next;
}