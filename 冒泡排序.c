#include<stdio.h>

void bubblesort(int a[],int n){
	int i = 0;
	for(i = 0;i<n;i++){
		int j = 0;
		for(;j<n-1;j++){
			if(a[j]>a[j+1]){
				int x = a[j];
				a[j] = a[j+1];
				a[j+1] = x;
			}
		}
		printf("%d\n",a[n-i-1]);
	}
}
int main()
{
	int a[] = {5,8,4,53,45,78,6,54};
	int n = sizeof(a)/sizeof(a[0]);
	bubblesort(a,n);
	int i = 0;
	for(;i<n;i++){
		printf("%d,",a[i]);
	} 
	return 0;
 } 
