#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

int main()
{
	int a[30][30];
	int c[30][30] = { 0 };
	int m = 0;
	int n = 0;
	scanf("%d %d", &m, &n);
	int i = 0;
	int j = 0;
	for (i = 0; i < m; i++){
		for (j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
			
		}
	}
	int k = 0;
	while (n-1){
		for (i = 0; i < m; i++){ 
			for (j = 0; j < m; j++){
				for (k = 0; k < m; k++){
					c[i][j] += a[i][k] * a[k][j];
				}
			}
		}
		n--;
	}
	for (i = 0; i < m; i++){
		for (j = 0; j < m; j++){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

