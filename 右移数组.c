#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

void rotate(int nums[], int l,int k){
	int c = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < k; i++){
		c = *(nums + l-1);
		for (j = l-1; j >=0; j--){
			
			*(nums + j) = *(nums+j-1);
			
		}
		*nums = c;
	}
	
}

int main()
{
	int a[100] = {1,2,3,4,5,6,7,8,9,10};
	int l = sizeof(a) / sizeof(a[0]);
	int k = 0;
	scanf("%d",&k);
	rotate(a, l, k%l);
	int i = 0;
	for (i = 0; i < l; i++){
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
