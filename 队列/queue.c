#include "queue.h"

void queueInit(Queue* q){
	//空队列
	q->_front = q->_rear = NULL;
	q->size = 0;
}
void queuePush(Queue* q, Datatype data){
	//创建节点
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	//尾插
	//如果是空队列
	if (q->_front == NULL){
		q->_front = q->_rear = node;
	}
	else{
		q->_rear->_next = node;
	}
	q->_rear = node;
	++q->size;
}
void queuePop(Queue* q){
	if (q->_front != NULL){
		Node* node = q->_front->_next;
		free(q->_front);
		q->_front = node;
		if (q->_front == NULL){
			q->_rear == NULL;
		}
	}
	--q->size;
}
Datatype queueFront(Queue* q){
	return q->_front->_data;
}
Datatype queueBack(Queue* q){
	return q->_rear->_data;
}
int queueEmpty(Queue* q){
	if (q->size == 0){
		return 1;
	}
	else{
		return 0;
	}
}