#include<stdio.h>
#include<stdlib.h>

//#define DateType int

typedef int DateType;
typedef struct seqlist
{
	//因为要动态开辟空间（堆上的空间），只能用指针访问此空间
	DateType* date;//存储类型
	size_t _size;//顺序表当前存放元素个数
	size_t _capacity;//顺序表最大可存放元素个数
}seqlist;

//操作接口：增删查改

//初始化顺序表
void seqinit(seqlist *sq){
	sq->date = NULL;
	sq->_capacity = 0;
	sq->_size = 0;
}

//判断顺序表是否已满
void checkCapacity(seqlist *sq){
	if (sq->_size == sq->_capacity){
		//顺序表已满，增容：1：开辟新空间；2：复制原地址空间内容；3:释放原空间
		size_t newCapacity = sq->_size == sq->_capacity ? 10 : 2 * sq->_capacity;
		//（1）malloc memcpy free
		DateType* newdata = (DateType*)malloc(newCapacity*sizeof(DateType));//开辟新空间
		memcpy(newdata, sq->date, sq->_size*sizeof(DateType));//拷贝原内容
		DateType *tem = sq->date;
		sq->date = newdata;//指向新空间
		free(tem);//释放原空间
		//（2）realloc
		sq->date = (DateType*)realloc(sq->date, newCapacity*sizeof(DateType));//一步到位
		sq->_capacity = newCapacity;
	}
}
//插入接口
//尾插：
void pushBack(seqlist *sq, DateType value){
	checkCapacity(sq);
	sq->date[sq->_size] = value;
	sq->_size++;//更新当前顺序表存放元素个数
}
//头插：
void pushFront(seqlist *sq, DateType value){
	//已有元素后移
	checkCapacity(sq);
	int i = sq->_size-1;
	for (; i >= 0; i--){
		sq->date[i + 1] = sq->date[i];
	}
	sq->date[0] = value;
	sq->_size++;
}
//任意位置：
void insert(seqlist *sq, DateType value){

}
//删除接口

//查找接口

