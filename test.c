#include<stdio.h>
#include<stdlib.h>

//#define DateType int

typedef int DateType;
typedef struct seqlist
{
	//��ΪҪ��̬���ٿռ䣨���ϵĿռ䣩��ֻ����ָ����ʴ˿ռ�
	DateType* date;//�洢����
	size_t _size;//˳���ǰ���Ԫ�ظ���
	size_t _capacity;//˳������ɴ��Ԫ�ظ���
}seqlist;

//�����ӿڣ���ɾ���

//��ʼ��˳���
void seqinit(seqlist *sq){
	sq->date = NULL;
	sq->_capacity = 0;
	sq->_size = 0;
}

//�ж�˳����Ƿ�����
void checkCapacity(seqlist *sq){
	if (sq->_size == sq->_capacity){
		//˳������������ݣ�1�������¿ռ䣻2������ԭ��ַ�ռ����ݣ�3:�ͷ�ԭ�ռ�
		size_t newCapacity = sq->_size == sq->_capacity ? 10 : 2 * sq->_capacity;
		//��1��malloc memcpy free
		DateType* newdata = (DateType*)malloc(newCapacity*sizeof(DateType));//�����¿ռ�
		memcpy(newdata, sq->date, sq->_size*sizeof(DateType));//����ԭ����
		DateType *tem = sq->date;
		sq->date = newdata;//ָ���¿ռ�
		free(tem);//�ͷ�ԭ�ռ�
		//��2��realloc
		sq->date = (DateType*)realloc(sq->date, newCapacity*sizeof(DateType));//һ����λ
		sq->_capacity = newCapacity;
	}
}
//����ӿ�
//β�壺
void pushBack(seqlist *sq, DateType value){
	checkCapacity(sq);
	sq->date[sq->_size] = value;
	sq->_size++;//���µ�ǰ˳�����Ԫ�ظ���
}
//ͷ�壺
void pushFront(seqlist *sq, DateType value){
	//����Ԫ�غ���
	checkCapacity(sq);
	int i = sq->_size-1;
	for (; i >= 0; i--){
		sq->date[i + 1] = sq->date[i];
	}
	sq->date[0] = value;
	sq->_size++;
}
//����λ�ã�
void insert(seqlist *sq, DateType value){

}
//ɾ���ӿ�

//���ҽӿ�

