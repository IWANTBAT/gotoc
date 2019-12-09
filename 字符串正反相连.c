#include<stdio.h>

#include<string.h>

int main() 

{

	char c[200]={"aaa"};

	char b[50];

	char *p1,*p2;

	gets(c);

	p1=c;

	p2=b+strlen(c);

	*p2--='\0';

	for(;p2>=b;p1++,p2--)

	{

		*p2=*p1;

	}

	strcat(c,b);

	puts(c);

	return 0;

}
