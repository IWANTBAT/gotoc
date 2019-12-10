#include<stdio.h>
#include<math.h>
int a[8],b[8];
int map[8][8]={{1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}};
int n=4,count=0;
void b_nqueen(int k);
void w_nqueen(int k);

void b_nqueen(int k)
{   int i,j;
    if(k==n)
	w_nqueen(0); 
    for(j=0;j<=n-1;j++)
    {	
       if(map[k][j]==0) continue;
       for(i=0;i<=k-1;i++)
	    if(a[i]==j||abs(j-a[i])==abs(i-k))  
               break;
	if(i==k)
	{   a[k]=j;	b_nqueen(k+1);  }
    }
}

void w_nqueen(int k)
{   int i,j;
    if(k==n)
    {	count++;
	return;
    }
    for(j=0;j<=n-1;j++)
    {	
       if(a[k]==j) continue;
       if(map[k][j]==0) continue;
       for(i=0;i<=k-1;i++)
	    if(b[i]==j||abs(j-b[i])==abs(i-k))  
               break;
	if(i==k)
	{   b[k]=j;	w_nqueen(k+1);  }
    }
}

int main()
{
	b_nqueen(0);
	printf(¡°%d\n¡±,count);
	return 0;
}

