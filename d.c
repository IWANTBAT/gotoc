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
		rint_an_integer(n / 10);//���ַ�����ӡ���Ľ���Ƿ���ģ������Ҫ������Ƚ���ӡ�������������������ӡ
		
	}
}
int main()
{
	int n = 0;
	printf("��������;\n");
	scanf("%d", &n);
	rint_an_integer(n);
	system("pause");
	return 0;
}

