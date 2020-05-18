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
	hp->_array = (Type*)malloc(sizeof(Type)*(size));
	memcpy(hp->_array, arr, sizeof(Type)*size);
	hp->_capacity = hp->_size = size;
	for (int i = (size - 2) / 2; i >= 0; i--){
		heapShiftDown(hp->_array, size, i);
	}

}

//���ϵ��������²���Ľڵ�λ����ʱ������������λ��С�ڸ��ڵ��ֵ�����Ѿ������ڵ㣨��ѵ�����
void heapShiftUp(Type* arr, int child){
	int parent = (child - 1)/ 2;
	while (parent >= 0 && arr[child] > arr[parent]){
		swap(arr, child, parent);
		child = parent;
		parent = (child - 1) / 2;
	}
}
//�ѵĲ��룺β��->��Ч�������ƻ��ѵĽṹ-->���ϵ��������µĽṹ��Ȼ�Ƕ�
void heapPush(heap* hp, Type data){
	//�������
	if (hp->_size == hp->_array){
		hp->_capacity *= 2;
		hp->_array = (Type*)realloc(hp->_array, sizeof(Type)*hp->_capacity);
	}
	//β��
	hp->_array[hp->_size++] = data;
	//���ϵ���
	heapShiftUp(hp->_array, hp->_size - 1);
}

//ֻɾ���Ѷ�Ԫ��

//���ֱ��ͷɾ��Ч�ʵͣ�O(n) �п����ƻ��ѵĽṹ
//��ȷ��ɾ����ʽ��
//1���Ѷ�Ԫ�غ����һ��Ҷ�ӽ�㽻��/����
//2��ִ��βɾ
//3�����µ���O(log(N))
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

