#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

int main()
{
	int a = 123;
	int c = 0;
	while (a){
		a = a&(a - 1);
		c++;
	}
	printf("%d\n", c);
	system("pause");
	return 0;
}
