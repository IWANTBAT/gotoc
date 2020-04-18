
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "List.h"

void listInit(List* lst)
{
	//��ʼ���յĴ�ͷ˫��ѭ������
	lst->_header = (ListNode*)malloc(sizeof(ListNode));
	lst->_header->_next = lst->_header;
	lst->_header->_prev = lst->_header;
}
ListNode* creatListNode(DataType data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = data;
	node->_prev = NULL;
	node->_next = NULL;
	return node;
}
void listPushBack(List* lst, DataType data)
{
	/*
	ListNode* node = creatListNode(data);
	ListNode* prev = lst->_header->_prev;
	prev->_next = node;
	node->_prev = prev;
	node->_next = lst->_header;
	lst->_header->_prev = node;
	*/
	listInsert(lst->_header, data);
}
void printList(List* lst)
{
	ListNode* cur = lst->_header->_next;
	while (cur != lst->_header)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void listPushFront(List* lst, DataType data)
{
	/*
	ListNode* node = creatListNode(data);
	ListNode* next = lst->_header->_next;
	lst->_header->_next = node;
	node->_prev = lst->_header;
	node->_next = next;
	next->_prev = node;
	*/
	listInsert(lst->_header->_next, data);
}

void listPopBack(List* lst)
{
	/*
	ListNode* header = lst->_header;
	
	if (header->_next == header)
	{
		//������,����ɾ��
		return;
	}
	
	ListNode* last = header->_prev;
	ListNode* prev = last->_prev;
	//ɾ�����һ���ڵ�
	free(last);

	prev->_next = header;
	header->_prev = prev;
	*/
	listErase(lst->_header->_prev);
}

void listPopFront(List* lst)
{
	/*
	ListNode* header = lst->_header;
	ListNode* first = header->_next;
	ListNode* next = first->_next;

	if (header->_next == header)
		return;
	free(first);
	header->_next = next;
	next->_prev = header;
	*/
	listErase(lst->_header->_next);
}

void listInsert(ListNode* pos, DataType data)
{
	ListNode* prev = pos->_prev;
	ListNode* newNode = creatListNode(data);
	// prev, newNode, pos
	newNode->_next = pos;
	pos->_prev = newNode;

	prev->_next = newNode;
	newNode->_prev = prev;
}
void listErase(ListNode* pos)
{
	if (pos->_next == pos)
		return;
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	prev->_next = next;
	next->_prev = prev;
	free(pos);
}

void listDestroy(List* lst)
{
	//�ӵ�һ����Ч���ݿ�ʼɾ��
	ListNode* cur = lst->_header->_next;
	//����Ұָ��Ͷ����ͷ�
	while (cur != lst->_header)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(lst->_header);
	lst->_header = NULL;
}
