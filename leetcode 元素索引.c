#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

int search(int *num, int numsize, int target)
{
	int *q = num;
	int *p = num + numsize -1;
	int mid = (p - q) / 2;
	printf("%d", mid);
	while (q <= p){	
		if (*q == target){
			return q - num;
		}
		if (*p == target){
			return p - num;
		}
		if (*q>target){
			return q - num;		
		}
		else{
			q++;
		}
		if (*p < target){
			if (p == numsize - 1){
				return numsize;
			}
			else{
				return p - num+1;
			}	
		}
		else{
			p--;
		}
	}
	return q - num;
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(a) / sizeof(a[0]);
	int target = 1;
	//scanf("%d",&size);
	int s = search(a, size, target);
	printf("%d\n", s);
	system("pause");
	return 0;
}
