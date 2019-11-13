#include<stdio.h>
int HuiWen(int n)
{
	int k=0;
	int p;
	p=n;
	while(p!=0)
	{
		k=k*10+p%10;
		p=p/10;
	}
	if(k==n)
	{
		return 1;
	} 
	
	else{
	return 0;
    } 
}
int main()
{
	int i;
	int result;
	for(i=1000;i<10000;i++)
	{
		result=HuiWen(i);
		if(1==result)
		{
	    printf("%d\n",i);
		}
	}
	return 0;
}
