#include<stdio.h>
int QKpass(int A[],int low,int high)
{
	int x ;
	x = A[low];
	while(low<high)
	{
		while(low<high&&A[high]>=x)
		high--;
		if(low<high)
		{
			A[low] = A[high];
			low++;
		}
		while(low<high&&A[low]<x)
		low++;
		if(low<high)
		{
			A[high] = A[low];
			high--;
		}
	}
	A[low] = x;
	return low;
 } 
 void QKsort(int A[],int low,int high)
 {
 	int pos;
 	if(low<high){
 		pos = QKpass(A,low,high);
 		QKsort(A,low,pos-1);
 		QKsort(A,pos+1,high);
	 }
 }
 int main()
 {
 	int N,i;
 	printf("输入数组长度：");
	 scanf("%d",&N);
	 int A[N];
	 printf("输入数组值：");
	 for(i = 0;i<N;i++){
	 	scanf("%d",&A[i]);
	 } 
	 QKsort(A,0,N-1);
	 for(i = 0;i<N;i++){
	 	printf("%d",A[i]);
	 	printf("\t");
	 }
	 return 0;
 }

