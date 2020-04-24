#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include"ListNode.h"

void listInit(List* lst){
	//初始化空的双向带头循环链表（头结点的加入是为了方便操作，所有操作都可以统一处理，不需要考虑是否为空链表的情况）
	lst->header = (ListNode*)malloc(sizeof(ListNode));
	lst->header->next = lst->header;
	lst->header->prev = lst->header;
}
ListNode* creatListNode(DataType data){
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
void listPushBack(List* lst, DataType data){
	//尾插(头的前驱就是尾结点)前驱后继都要链接
	ListNode* node = creatListNode(data);
	ListNode* prev = lst->header->prev;
	node->next = lst->header;
	node->prev = prev;
	prev->next = node;
	lst->header->prev = node;
}

void PrintList(List* lst){
	//打印链表
	ListNode* cur = lst->header->next;
	while (cur != lst->header){
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void listPushFront(List* lst, DataType data){
	//头插 
	ListNode* node = creatListNode(data);
	ListNode* next = lst->header->next;
	lst->header->next = node;
	node->next = next;
	node->prev = lst->header;
	next->prev = node;
}
void listPopBack(List* lst){
	//尾删（不能删除header，会破坏结构）
	ListNode* header = lst->header;
	if (header->next == header){
		return;
	}
	ListNode* last = header->prev;
	ListNode* prev = last->prev;
	free(last);
	prev->next = header;
	header->prev = prev;
}
void listPopFront(List* lst){
	//头删
	ListNode* head = lst->header;
	ListNode* first = head->next;
	ListNode* next =first->next;
	if (head->next == head){
		return;
	}
	free(first);
	head->next = next;
	next->prev = head;
}
void listInsert(ListNode* pos, DataType data){
	//在pos之前插入
	ListNode* prev = pos->prev;
	ListNode* node = creatListNode(data);
	node->next = pos;
	pos->prev = node;
	prev->next = node;
	node->prev = prev;
}
void listErase(ListNode* pos){
	if (pos->next == pos){
		return;
	}
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}
//
//
void ListDestroy(List* lst){
	//销毁链表
	ListNode* cur = lst->header->next;
	while (cur != lst->header)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(lst->header);
	lst->header = NULL;
}

