typedef int Datatype;

typedef struct stack
{
	Datatype* _array;
	size_t _size;
	size_t _capacity;
}stack;


void stackInit(stack* st, size_t n){
	st->_array = (Datatype*)malloc(sizeof(Datatype)*n);
	st->_size = 0;
	st->_capacity = n;
}
//入栈
void stackPush(stack* st, Datatype data){
	//检查容量
	if (st->_size == st->_capacity){
		st->_array = (Datatype*)malloc(sizeof(Datatype)* 2 * st->_capacity);
		st->_capacity *= 2;
	}
	st->_array[st->_size++] = data;
}

//出栈
void stackPop(stack* st){
	if (st->_size > 0){
		--st->_size;
	}
}

//栈顶元素
Datatype stackTop(stack* st){
	return st->_array[st->_size - 1];
}

//元素个数
size_t stackSize(stack* st){
	return st->_size;
}

//是否为空
int stackEmpty(stack* st){
	if (st->_size <= 0){
		return 1;
	}
	else{
		return 0;

	}

}

//销毁栈
void stackDestory(stack* st){
	if (st->_array){
		free(st->_array);
		st->_size = st->_capacity = 0;
	}
}

typedef struct {
	stack Pushst;
	stack Popst;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
	stackInit(&mq->Pushst, 10);//入队栈
	stackInit(&mq->Popst, 10);//出队栈
	return mq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	//入队栈进行入栈
	stackPush(&obj->Pushst, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	//先判断出队栈是否为空
	if (stackEmpty(&obj->Popst)){
		while (stackEmpty(&obj->Pushst) != 1){
			int e = stackTop(&obj->Pushst);
			stackPop(&obj->Pushst);
			stackPush(&obj->Popst, e);
		}
	}
	int ret = stackTop(&obj->Popst);
	stackPop(&obj->Popst);
	return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	//先判断出队栈是否为空
	if (stackEmpty(&obj->Popst)){
		while (stackEmpty(&obj->Pushst) != 1){
			int e = stackTop(&obj->Pushst);
			stackPop(&obj->Pushst);
			stackPush(&obj->Popst, e);
		}
	}
	return  stackTop(&obj->Popst);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	if (stackEmpty(&obj->Pushst) && stackEmpty(&obj->Popst)){
		return true;
	}
	return false;
}

void myQueueFree(MyQueue* obj) {
	stackDestory(&obj->Pushst);
	stackDestory(&obj->Popst);
	free(obj);
}

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/