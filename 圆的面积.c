#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	int F[n]; 
	F[0] = F[1] =1;
	for(i = 2;i<n;i++)
	{
		F[i] = (F[i-1] + F[i-2])%10007;
		printf("%d\t",F[i]);
	}
	printf("%d\n",F[n-1]);
	return 0;
 } 
