#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

int removeElement(int nums[], int l,int val){
	//int *a = nums;
	int count = 0;
	int i = 0;
	while (i < l){
		if (*(nums+i) == val){
			
		}
		else{
			*(nums+count) = *(nums+i);
			count++;
		}
		i++;
	}
	
	return count;
}
int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 2, 10 };
	int val = 0;
	scanf("%d", &val);;
	int s = sizeof(a) / sizeof(a[0]);
	int b = removeElement(a,s,val);
	printf("%d\n", b);
	system("pause");
	return 0;
}
