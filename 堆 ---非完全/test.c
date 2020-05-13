#include"heap.h"

void test(){
	heap hp;
	int arr[] = { 1, 10, 30, 5, 2, 4, 100, 6, 7 };
	heapInit(&hp, arr, sizeof(arr) / sizeof(arr[0]));

}
int main()
{
	test();
	return 0;
}
