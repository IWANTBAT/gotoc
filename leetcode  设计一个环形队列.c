typedef struct {
	int* _array;
	int _front;
	int _rear;
	int _k;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	q->_array = (int*)malloc(sizeof(int)*(k + 1));
	q->_front = q->_rear = 0;
	q->_k = k;
	return q;
}
/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->_rear == obj->_front){
		return true;
	}
	return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if ((obj->_rear + 1) % (obj->_k + 1) == obj->_front){//刚开始写的是if(obj->_rear + 1 % (obj->_k+1) == obj->_front),结果找了半天bug。这里是因为操作符%比+的优先级高，所以出现bug，这种bug真的是太难找了啊啊啊
		return true;
	}
	return false;
}
/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	//判断队列是否已满
	if (myCircularQueueIsFull(obj)){
		return false;
	}
	//队尾插入
	obj->_array[obj->_rear++] = value;
	//判断队尾是否越界
	if (obj->_rear == obj->_k + 1){
		obj->_rear = 0;
	}
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	//判断队列是否为空
	if (myCircularQueueIsEmpty(obj)){
		return false;
	}
	//队头出队
	++obj->_front;
	//判断队头是否越界
	if (obj->_front == obj->_k + 1){
		obj->_front = 0;
	}
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj)){
		return -1;
	}
	return obj->_array[obj->_front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj)){
		return -1;
	}
	if (obj->_rear == 0){
		return obj->_array[obj->_k];
	}
	return obj->_array[obj->_rear - 1];
}



void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->_array);
	free(obj);
}

/**
* Your MyCircularQueue struct will be instantiated and called as such:
* MyCircularQueue* obj = myCircularQueueCreate(k);
* bool param_1 = myCircularQueueEnQueue(obj, value);

* bool param_2 = myCircularQueueDeQueue(obj);

* int param_3 = myCircularQueueFront(obj);

* int param_4 = myCircularQueueRear(obj);

* bool param_5 = myCircularQueueIsEmpty(obj);

* bool param_6 = myCircularQueueIsFull(obj);

* myCircularQueueFree(obj);
*/