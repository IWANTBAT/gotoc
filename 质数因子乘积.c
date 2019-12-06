#include<stdio.h>
int main()
{
	int  x,i;
	while(scanf("%d",&x)!=EOF)
	{
		i=2;
		while(1)
		{
		    if(i==x)
			{
				printf("%d\n",i);
				break;
			}
			if(x%i==0)
			{
				printf("%d*",i);
				x/=i;
			}
			else
			{
				++i;  
			}
		}
	}
	return 0;
}
