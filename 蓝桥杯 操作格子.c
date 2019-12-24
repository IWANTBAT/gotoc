#include <stdio.h>
 
int main()
{
	int n,m;
	int *a;			
	int p,x,y;
	int sum, max;	 
	int i,j;
 
	scanf("%d%d",&n,&m);
	a=malloc(n*sizeof(int));		// int a[100000];

	for(i=0;i<n;i++)
		scanf("%d",a+i);
for(i=0;i<m;i++)
	{	scanf("%d%d%d",&p,&x,&y);
 
		switch(p)
		{
		case 1: a[x-1]=y; break;
		case 2:
			sum=0;
			for(j=x-1;j<y;j++)
				sum+=a[j];	
			printf("%d\n",sum);
			break;
		case 3:
			max=a[x-1];
			for(j=x;j<y;j++)
				if(a[j]>max) max=a[j];
			printf("%d\n",max);			
		}		
	} 
	return 0;
}
