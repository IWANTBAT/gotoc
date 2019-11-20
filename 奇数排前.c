



#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

void F(int* l,int* r){
	int temp = 0;
	while (l < r){
		while (1 == (*l % 2)){
			l++;
		}
		while (0 == (*r % 2)){
			r--;
		}
		if (l < r){
			temp = *l;
			*l = *r;
			*r = temp;
		}
	}
}
void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int i = 0;
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* l = arr;
	int* r = arr + sz-1;
	F(l,r);
	for (i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}
