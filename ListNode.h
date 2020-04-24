typedef int DataType;

typedef struct ListNode{
	struct ListNode* next;
	struct ListNode* prev;
	DataType data;
}ListNode;

typedef struct List{
	ListNode* header;
}List;

void listInit(List* lst);//≥ı ºªØ

ListNode* creatListNode(DataType data);
void listPushBack(List* lst, DataType data);
void listPushFront(List* lst, DataType data);
void listPopBack(List* lst);
void listPopFront(List* lst);
void listInsert(ListNode* pos, DataType data);
void listErase(ListNode* pos);

void PrintList(List* lst);
void ListDestroy(List* lst);