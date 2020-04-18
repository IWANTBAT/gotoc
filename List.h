typedef int DataType;

typedef struct ListNode
{
	struct ListNode* _next;
	struct ListNode* _prev;
	DataType _data;
} ListNode;

typedef struct List
{
	ListNode* _header;
}List;
void listInit(List* lst);
ListNode* creatListNode(DataType data);
void listPushBack(List* lst, DataType data);
void listPushFront(List* lst, DataType data);
void listPopBack(List* lst);
void listPopFront(List* lst);
//在pos前面插入
void listInsert(ListNode* pos, DataType data);
//删除pos执向的数据
void listErase(ListNode* pos);

void printList(List* lst);
void listDestroy(List lst);
