#pragma once

#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
typedef int Type;

typedef struct heap{
	Type* _array;
	size_t _size;
	size_t _capacity;
}heap;

//void heapInit(heap* hp);

void heapInit(heap* hp, Type* arr, size_t size);

void heapShiftDown(Type * arr, size_t size, int parent);

void heapPush(heap* hp, Type data);

void heapPop(heap* hp);

int heapSize(heap* hp);

int heapEmpty(heap* hp);