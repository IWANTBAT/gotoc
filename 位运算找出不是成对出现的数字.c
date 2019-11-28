#include<stdio.h>
#include<windows.h>

int main()
{
	int i = 0;
	int x = 0;
	int a[11];
	for (int i = 0; i < 11; i++){
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 11; i++){
		x = x ^ a[i];
	}
	printf("%d", x);
	system("pause");
	return 0;
}

