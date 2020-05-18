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
	hp->_array = (Type*)malloc(sizeof(Type)*(size));
	memcpy(hp->_array, arr, sizeof(Type)*size);
	hp->_capacity = hp->_size = size;
	for (int i = (size - 2) / 2; i >= 0; i--){
		heapShiftDown(hp->_array, size, i);
	}

}

//向上调整：从新插入的节点位置来时，到待调整的位置小于父节点的值或者已经到根节点（大堆调整）
void heapShiftUp(Type* arr, int child){
	int parent = (child - 1)/ 2;
	while (parent >= 0 && arr[child] > arr[parent]){
		swap(arr, child, parent);
		child = parent;
		parent = (child - 1) / 2;
	}
}
//堆的插入：尾插->高效，不会破坏堆的结构-->向上调整：让新的结构仍然是堆
void heapPush(heap* hp, Type data){
	//检查容器
	if (hp->_size == hp->_array){
		hp->_capacity *= 2;
		hp->_array = (Type*)realloc(hp->_array, sizeof(Type)*hp->_capacity);
	}
	//尾插
	hp->_array[hp->_size++] = data;
	//向上调整
	heapShiftUp(hp->_array, hp->_size - 1);
}

//只删除堆顶元素

//如果直接头删：效率低；O(n) 有可能破坏堆的结构
//正确的删除方式：
//1：堆顶元素和最后一个叶子结点交换/覆盖
//2：执行尾删
//3：向下调整O(log(N))
void heapPop(heap* hp){
	if (hp->_size > 0){
		hp->_array[0] = hp->_array[hp->_size - 1];
		hp->_size--;
		heapShiftDown(hp->_array, hp->_size, 0);
	}
}

int heapSize(heap* hp){
	return hp->_size;
}

int heapEmpty(heap* hp){
	if (hp->_size == 0){
		return 1;
	}
	return 0;
}

Type heapTop(heap* hp){
	return hp->_array[0];
}

