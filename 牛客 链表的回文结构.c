/*牛客 链表的回文结构
对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
*/
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/

		//时间复杂度为O(n);空间复杂度为O(n)
		bool chkPalindrome(ListNode* A) {
			// write code here
			if (A == NULL || A->next == NULL){
				return true;
			}
			struct ListNode* nh;
			struct ListNode* nt;
			//创建新表头（也可以创建两个新表头，一个拷贝前半部分的，一个拷贝后半部分的，然后逆转其中一个，最后进行对比）
			nh = nt = (struct ListNode*)malloc(sizeof(struct ListNode));
			nh->val = A->val;
			struct ListNode* cur = A->next;
			int len = 1;
			//拷贝链表
			while (cur){
				struct ListNode* nd = (struct ListNode*)malloc(sizeof(struct ListNode));
				nd->val = cur->val;
				nd->next = NULL;
				nt->next = nd;
				nt = nt->next;
				cur = cur->next;

				len++;
			}
			//逆转链表
			struct ListNode* prev = NULL;
			cur = nh;
			while (cur){
				struct ListNode* next = cur->next;
				cur->next = prev;
				prev = cur;
				cur = next;
			}
			nh = prev;
			len /= 2;
			nt = nh;
			cur = A;
			//已经逆转，相当于对比前半部分和后半部分
			while (len--){
				if (cur->val != nt->val){
					return false;
				}
				cur = cur->next;
				nt = nt->next;
			}
			return true;//到此说明是回文
		}
	};

	/*
	二：逆转链表的后半部分，然后前半部分和后半部分同时便利进行对比，知道某一结点为空结束；
	*/

	class PalindromeList {
	public:
		bool chkPalindrome(ListNode* A) {
			// write code here
			if (A == NULL || A->next == NULL){
				return true;
			}
			//快慢指针找出中间节点
			struct ListNode* slow;
			struct ListNode* fast;
			fast = slow = A;
			while (fast && fast->next){//fast 以及fast->next不为空是继续循环
				slow = slow->next;
				fast = fast->next->next;
			}//slow为中间节点,如果是偶数，为第二个中间节点
			struct ListNode* prev = NULL;
			struct ListNode* cur = slow;
			while (cur){
				struct ListNode* next = cur->next;
				cur->next = prev;
				prev = cur;
				cur = next;
			}
			cur = prev;
			while (A && cur){
				if (A->val != cur->val){
					return false;
				}
				cur = cur->next;
				A = A->next;
			}
			return true;

		}
	};

	/*也可用数组，但不建议*/
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