#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void rint_an_integer(int n)
{
	if (n < 10){
		printf("%d", n);
	}
	else{
		printf("%d\n", n % 10);
		rint_an_integer(n / 10);//这种方法打印出的结果是反序的，如果需要正序就先将打印的数存入数组在逆序打印
		
	}
}
int main()
{
	int n = 0;
	printf("输入数字;\n");
	scanf("%d", &n);
	rint_an_integer(n);
	system("pause");
	return 0;
}

