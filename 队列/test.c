#include"queue.h"
void test(){
	Queue q;
	queueInit(&q);
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	queuePush(&q, 4);
	queuePush(&q, 5);
	while (queueEmpty(&q) != 1){
		printf("%d ", queueFront(&q));
		queuePop(&q);
	}
}
int main()
{
	test();
	return 0;
}