#include<stdio.h>
#include<windows.h>
#include<math.h>
#pragma warning(disable:4996)

void f(char* l, int n){
	char c = *l;
	int i = 1;
	while (i < n - 1){
		*(l+i-1) = *(l + i);
		i++;
	}
	*(l+i-1) = c;
}
int main()
{
	char a[] = "ABCD";
	int n = sizeof(a) / sizeof(a[0]); 
	int x = 0;
	scanf("%d", &x);
	while (x){
		f(a, n);
		x--;
	}
	puts(a);
	system("pause");
	return 0;
}
