#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	int a = 0;
	scanf("%d", &a);
	int i = 0;
	int  A[16];
	int  B[16];
	int j = 0;
	int k = 0;
	for (i = 0; i < 32; i++){
		if (i % 2 == 0){
			A[j] = (a%2)^0;
			j++;
		}
		else{
			B[k] = (a%2)^0;
			k++;
		}
		a >>= 1;
	}
	for (i = 0; i < 16; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
	for (i = 0; i < 16; i++){
		printf("%d ", B[i]);
	}
	system("pause");
	return 0;
}
