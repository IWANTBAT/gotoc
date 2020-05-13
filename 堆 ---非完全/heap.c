#include"heap.h"


void heapInit(heap* hp);


void swap(Type* arr, int left, int right){
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}
//大堆调整
void heapShiftDown(Type * arr, size_t size, int parent){
	//计算孩子的位置
	int child = 2 * parent + 1;
	while (child < size){
		//从两个孩子中选最大值
		if (child + 1 < size && arr[child + 1] > arr[child]){
			++child;
		}
		//如果父节点小于最大的孩子节点，交换
		if (arr[parent] < arr[child]){
			swap(arr, child, parent);
		    parent = child;
		    child = 2 * parent + 1;
		}
		else{
			//父亲节点大于所有孩子节点，整体即为大堆
			break;
		}
	}
}
void heapInit(heap* hp, Type* arr, size_t size){
	//从最后一个非叶子节点开始向下调整
	for (int i = (size - 2) / 2; i >= 0; i--){
		heapShiftDown(arr, size, i);
	}
	hp->_array = (Type*)malloc(sizeof(Type)*(size));
	memcpy(hp->_array, arr, sizeof(Type)*size);
	hp->_capacity = hp->_size = size;
}


void heapPush(heap* hp, Type data);

void heapPop(heap* hp);

int heapSize(heap* hp);

int heapEmpty(heap* hp);

