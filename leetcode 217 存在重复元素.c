#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
//»Øµ÷º¯Êý
int cmp_int(const void* _a, const void* _b)
	{
		int* a = (int*)_a;  
		int* b = (int*)_b;
		return *a - *b;
	}

int containsDuplicate(int* nums, int numsSize){
	qsort(nums, numsSize, sizeof(nums[0]), cmp_int);
	int i = 0;
	for (; i < numsSize-1; i++){
		int j = i + 1;
		if (nums[i] == nums[j]){
			return 1;
		}
	}
	return 0;
}

int main()
{
	int nums[] = { 1, 2, 3, 3, 2, 5, 8 };
	int size = sizeof(nums) / sizeof(nums[0]);
	int a = containsDuplicate(nums, size);
	printf("%d\n", a);
	system("pause");
	return 0;
}
