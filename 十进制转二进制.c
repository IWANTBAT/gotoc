#include<stdio.h>
void convert(int n)
{
	if(n > 1)
	{
		convert(n/2);
    } 
	printf("%d",n%2);
}
int main()
{
	int n;
	scanf("%d",&n);
	convert(n);
	return 0;
}

