#include<stdio.h>
#include<assert.h>
#include<windows.h>

int find(int a[], int num, int *xp, int *yp)
{
	assert(a);
	assert(num >= 2);
	assert(xp);
	assert(yp);
	int result = a[0];
	int i = 1;
	for (; i < num; i++){
		result ^= a[i];
	}
	int j = 0;
	int flag = 1;
	while (j < 32){
		if (result & flag){
			break;
		}
		flag <<= 1;
		j++;
	}

	for (i = 0; i < num; i++){
		if (a[i] & flag){
			*xp ^= a[i];
		}
		else{
			*yp ^= a[i];
		}
	}
	return 0;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 8, 7, 4, 5, 6, 1, 2, 3, 12, 52 };
	int num = sizeof(a) / sizeof(a[0]);
	int x = 0;
	int y = 0;
	find(a, num, &x, &y);
	printf("%d %d\n", x, y);
	system("pause");
	return 0;
}
