#include<stdio.h>

void strcppy(char *p, char *q){
	*p = *q; 
}
int main()
{
	char a[20] = "hellow";
	char b[10] = " world";
	int size = strlen(a);
	int size1 = strlen(b);
	char *p = a + size;
	char *q = b;
	
	int i = 0;
	for (i = 0; i < size1; i++){
		strcppy(p, q);
		q++;
		p++;
	}
	puts(a);
	return 0;
}
