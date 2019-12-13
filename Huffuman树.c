#include<stdio,h>
 void sort(int *a,int n)
{
	int i,j,t;
	for(i=1;i<=n-1;i++)
		for(j=1;j<=n-i;j++)
			if(a[j]<a[j+1])
			{t=a[j];a[j]=a[j+1];a[j+1]=t;}
}

int main()
{
	int a[100]={10000000,5,3,8,2,9};
	int n=5,i,newd,sum=0;
	sort(a,n);
	while(n>2)
	{
		newd=a[n-1]+a[n];
		sum+=newd;
		i=n-2;
		while(a[i]<newd)
		{    a[i+1]=a[i];i--;	}
		a[i+1]=newd;
		n--;
	}
	printf("%d\n",a[2]+a[1]+sum);
	return 0;
}

