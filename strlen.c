//·Çµİ¹é
#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	char str[100];
	printf("ÊäÈë×Ö·û´®:\n");
	gets(str);
	int count = 0;
	while (str[count] != '\0'){
		count++;
	}
	printf("%d\n", count);
	system("pause");
	return 0; 
}

//µİ¹é
#include<stdio.h>
#pragma warning(disable:4996)
#include<windows.h>
int strl(char* str){
	if (*str == '\0'){
		return 0;
	}
	else{
		return 1 + strl(str + 1);
	}
}
int main()
{
	char str[] = "aidkjdnf";
	int l = strl(str);
	printf("%d\n", l);
	system("pause");
	return 0;
}
