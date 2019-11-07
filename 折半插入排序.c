#include<stdio.h>

void BinSort(int a[],int lengh){
	int i = 1;
	for(;i<lengh;++i){
		int x = a[i];
		int low = 0;
		int high = i-1;
		while(low<=high){
			int mid = (low + high)/2;
			if(x<a[mid]){
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		int j = i-1;
		for(;j>=low;--j){
		a[j+1] = a[j];
		}	a[low] = x;
	}
}
int main()
{
	int a[] = {48,62,35,77,55,14,35,98};
	int lengh = sizeof(a)/sizeof(a[0]);
	BinSort(a,lengh);
	int i = 0;
	for(;i<lengh;i++){
		printf("%d,",a[i]);
	}
	return 0;
} 
