/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* swapPairs(struct ListNode* head){
	if (head == NULL || head->next == NULL) return head;
	else{
		struct ListNode*p = head, *q, *m, *n, *r = head->next;
		int i, len = 0;
		while (p)
		{
			p = p->next;
			len++;
		}
		p = head;
		q = head->next;
		for (i = 1; i<(len / 2); i++)
		{
			m = p;
			n = q;
			p = p->next->next;
			q = q->next->next;
			n->next = m;
			m->next = q;
		}
		if (len % 2 == 0)
		{
			q->next = p;
			p->next = NULL;
		}
		else
		{
			p->next = q->next;
			q->next = p;
		}
		return r;
	}
}

