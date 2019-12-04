#include<stdio.h>
#include<string.h>

int main()
{ 
    int a[20];
    int count,k;
    while(scanf("%d",&a[0])!=EOF&&a[0]!=-1)
    {
        k=1;
		count=0;
        while(scanf("%d",&a[k])!=EOF&&a[k])
			k++;
		int i = 0;
        for(i = 0;i<=k;i++){
        	int j  = 0;
        	for(j=0;j<k;j++)
        	   if(a[i]==2*a[j])
                   count++;
		}
        printf("%d\n",count);
    }
}

