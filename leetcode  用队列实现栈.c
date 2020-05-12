typedef int Datatype;

typedef struct Node{
	struct Node* _next;
	Datatype _data;
}Node;

typedef struct Queue{
	//头尾指针
	Node* _front;
	Node* _rear;
	size_t size;
}Queue;

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
	return 0;
}
size_t queueSize(Queue* q){
	return q->size;
}
void queueDestory(Queue* q){
	Node* cur = q->_front;
	while (cur){
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
	q->size = 0;
}
typedef struct {
	Queue _q;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	queueInit(&ms->_q);
	return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	queuePush(&obj->_q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int sz = queueSize(&obj->_q);
	while (sz > 1){
		int tmp = queueFront(&obj->_q);
		queuePop(&obj->_q);
		queuePush(&obj->_q, tmp);
		sz--;
	}
	int ret = queueFront(&obj->_q);
	queuePop(&obj->_q);
	return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	return queueBack(&obj->_q);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	if (queueEmpty(&obj->_q)){
		return true;
	}
	return false;
}

void myStackFree(MyStack* obj) {
	queueDestory(&obj->_q);
	free(obj);
}
/**
* Your MyStack struct will be instantiated and called as such:
* MyStack* obj = myStackCreate();
* myStackPush(obj, x);

* int param_2 = myStackPop(obj);

* int param_3 = myStackTop(obj);

* bool param_4 = myStackEmpty(obj);

* myStackFree(obj);
*/