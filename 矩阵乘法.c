#include<stdio.h>

int main()
{
	int m,s,n,i,j,k;
	scanf("%d %d %d",&m,&s,&n);
	int a[m][s];
	int b[s][n];
	int c[m][n];
	for(i = 0;i<m;i++){
		for(j = 0;j<n;j++){
			c[i][j] = 0;
		}
	}
	for(i = 0;i<m;i++){
		for(j = 0;j<s;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i = 0;i<s;i++){
		for(j = 0;j<n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(i = 0;i<m;i++){
		for(k = 0;k<n;k++){
			for(j = 0;j<s;j++){
				c[i][k] += a[i][j] * b[j][k];
			}
		}
	}
	for(i = 0;i<m;i++){
		for(j = 0;j<n;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
