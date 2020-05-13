#include"heap.h"


void heapInit(heap* hp);


void swap(Type* arr, int left, int right){
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}
//��ѵ���
void heapShiftDown(Type * arr, size_t size, int parent){
	//���㺢�ӵ�λ��
	int child = 2 * parent + 1;
	while (child < size){
		//������������ѡ���ֵ
		if (child + 1 < size && arr[child + 1] > arr[child]){
			++child;
		}
		//������ڵ�С�����ĺ��ӽڵ㣬����
		if (arr[parent] < arr[child]){
			swap(arr, child, parent);
		    parent = child;
		    child = 2 * parent + 1;
		}
		else{
			//���׽ڵ�������к��ӽڵ㣬���弴Ϊ���
			break;
		}
	}
}
void heapInit(heap* hp, Type* arr, size_t size){
	//�����һ����Ҷ�ӽڵ㿪ʼ���µ���
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

