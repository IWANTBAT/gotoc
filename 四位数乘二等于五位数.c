#include<stdio.h>
int main()
{
	int x,y,i;
	int m = 0;
	int n = 0;int temp =0;
	int A[4];
	int B[5]; int f;
	for(i = 5000;i<=9999;i++)
	{
		x = i;y = 2*i;
		if(y>=10000&&y<=99999)
		{
			if(x!=0){
			A[m] = x%10;
			x = x/10;
			m++;
	      	}
	      	if(y!=0){
	      		B[n] = y%10;
				y = y/10;
				n++;
			}
		}
	   int judge[10] = {0};
	   for(f = 0;f<4;f++){
	   	judge[A[f]]++;
	   }
	   for(f = 0;f<5;f++){
	   	judge[B[f]]++;
	   }
	   for(f = 0;f<10;f++){
		  if(judge[f]>1)
		   {
		    	temp = 1;
		    	break;
	       }
	    }
	   if(temp == 0)
	   printf("%d\t%d\n",i,i*2); 
	}
	return 0;
 }

