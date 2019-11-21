#include<stdio.h>
int main()
{
	int i =0;
	char a[20];
	gets(a);
	for(;i<20;i++){
		if(a[i] == '\0'){
			break;
		}
		if(a[i]>='A'&&a[i]<='Z'){
			a[i] = a[i] + 32; 
		}
		else if(a[i]>='a'&&a[i]<='z'){
			a[i] = a[i] - 32;
		}
	}
	puts(a);
	return 0;
}
