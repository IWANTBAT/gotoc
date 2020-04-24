#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include"ListNode.h"

void listInit(List* lst){
	//��ʼ���յ�˫���ͷѭ������ͷ���ļ�����Ϊ�˷�����������в���������ͳһ��������Ҫ�����Ƿ�Ϊ������������
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
	//β��(ͷ��ǰ������β���)ǰ����̶�Ҫ����
	ListNode* node = creatListNode(data);
	ListNode* prev = lst->header->prev;
	node->next = lst->header;
	node->prev = prev;
	prev->next = node;
	lst->header->prev = node;
}

void PrintList(List* lst){
	//��ӡ����
	ListNode* cur = lst->header->next;
	while (cur != lst->header){
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void listPushFront(List* lst, DataType data){
	//ͷ�� 
	ListNode* node = creatListNode(data);
	ListNode* next = lst->header->next;
	lst->header->next = node;
	node->next = next;
	node->prev = lst->header;
	next->prev = node;
}
void listPopBack(List* lst){
	//βɾ������ɾ��header�����ƻ��ṹ��
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
	//ͷɾ
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
	//��pos֮ǰ����
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
	//��������
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

