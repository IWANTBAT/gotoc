#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
#define N 2
#define M N+1
#define NUM (M+1)*M/2
int main()
{
	printf("%d\n", NUM);
	//define 只是宏定义中单纯的替换  即：
	printf("%d\n", (N + 1 + 1)*N + 1 / 2);

	system("pause");
	return 0;
}
