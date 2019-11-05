#include<stdio.h>
void insSort(int a[],int lengh){
	int i = 1;
	for(;i<lengh;i++){
		int x = a[i];
		int j = i-1;
		while(x<a[j]){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}
int main()
{
	int a[] = {48,62,35,77,55,14,35,98};
	int lengh = sizeof(a)/sizeof(a[0]);
	insSort(a,lengh);
	int i = 0;
	for(;i<lengh;i++){
		printf("%d,",a[i]);
	}
	return 0;
 } 
