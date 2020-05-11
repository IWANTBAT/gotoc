#pragma once
#include<stdio.h>
typedef int Datatype;

typedef struct Node{
	struct Node* _next;
	Datatype _data;
}Node;

typedef struct Queue{
	//Õ∑Œ≤÷∏’Î
	Node* _front;
	Node* _rear;
	size_t size;
}Queue;

void queueInit(Queue* q);

void queuePush(Queue* q, Datatype data);

void queuePop(Queue* q);

Datatype queueFront(Queue* q);

Datatype queueBack(Queue* q);

int queueEmpty(Queue* q);

size_t queueSize(Queue* q);