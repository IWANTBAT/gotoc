#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning(disable:4996)

int p(char a[], char b[]){
	int a1 = strlen(a);
	int b1 = strlen(b);
	int i = 0;
	int j = a1;
	while(j){
		char t = a[0];
		for (i = 0; i < a1 - 1; i++){
			a[i] = a[i + 1];
		}
		a[a1 - 1] = t;
		if (0 == strcmp(a, b)){
			return 1;
		}
		j--;
	}
	return 0;
}
int main()
{
	char a[] = "AABCD";
	char b[] = "BCDAA";
	int c = p(a, b);
	printf("%d\n", c);
	system("pause");
	return 0;
}

