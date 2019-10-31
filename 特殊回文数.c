#include<stdio.h>
int main()
{
	int n,i,a,b,c,d,e,f,sum;
	scanf("%d",&n);
	for(i = 10000;i<=99999;i++)
	{
		a = i/10000;
		b = i/1000%10;
		c = i/100%10;
		d = i/10%10;
		e = i%10;
		sum = a+b+c+d+e;
		if((a*100+b*10 == e*100+d*10)&&sum == n)
		{
			printf("%d\n",i);
		}
	}
	for(i = 100000;i<=999999;i++)
	{
		a = i/100000;
		b = i/10000%10;
		c = i/1000%10;
		d = i/100%10;
		e = i/10%10;
		f = i%10;
		sum = a+b+c+d+e+f;
		if((a*100+b*10+c == f*100+e*10+d)&&sum == n)
		{
			printf("%d\n",i);
		}
	}
	return 0;
 } 
