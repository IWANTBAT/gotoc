#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

void f (int a[30][30], int b[30][30], int n)
{
    int i, j, c[30][30]={0}, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++)
                c[i][j] += b[i][k] * a[k][j];
        }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)   
	   b[i][j] = c[i][j];
        
}
int main() {
    int a[30][30], b[30][30]={0}, i, j, m, n;

    scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)	b[i][i]=1;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) 
            scanf("%d", &a[i][j]);
          
    for (i = 0; i < m; i++)
        f(a, b, n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
  return 0;
}

