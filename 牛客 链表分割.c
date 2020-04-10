/*牛客 链表分割
编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变（这里的顺序不变理解为相对位置不变）
*/
/*
创建两个表头：一个是小于x的；一个是大于等于x的；
遍历链表，小于x的放在第一个表尾，大于等于的放在第二个；
遍历结束后拼接两个链表
返回第一个链表的表头的next
*/

ListNode* partition(ListNode* pHead, int x) {
	//创建两个新表头
	struct ListNode* n1;//存放小于x的节点
	struct ListNode* n2;//存放大于等于x的节点
	n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n = n1;
	struct ListNode* m = n2;
	while (pHead){
		if (pHead->val < x){
			n->next = pHead;
			n = n->next;
		}
		else{
			m->next = pHead;
			m = m->next;
		}
		pHead = pHead->next;
	}
	m->next = NULL;//链表尾部指向NULL
	n->next = n2->next;//拼接链表
	struct ListNode* head = n1->next;
	free(n1);//释放动态开辟的空间。避免内存泄漏
	free(n2);
	return head;
}
};