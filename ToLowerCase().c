#include<stdio.h>
#include<windows.h>
#pragma warning(disble:4996)

char* toLowerCase(char* str){
	char* a = str;
	while (*str != '\0'){
		if (*str >= 'A' && *str <= 'Z'){
			*str = (*str ) + 32;
		}
		str++;
	}
	return a;
}
int main()
{
	char a[] = "ASDASBDasds";
	char *s =  toLowerCase(&a);
	printf("%s",s);
	system("pause");
	return 0;
}
