#include<stdio.h>

int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int x = 0;
	scanf("%d",&x);
	char gro[100][100];
	int i = 0;int j = 0;

	for(i = 0;i<m;i++){
		for(j = 0;j<n;j++){
			scanf("%c",&gro[i][j]);
		}
	}
	while(x){
	int a[m][n] = {0};
		for(i = 0;i<m;i++){
			for(j = 0;j<n;j++){
				if((gro[i][j] == 'g')&&a[i][j] == 0){
				if (i - 1>=0){
						gro[i - 1][j] = 'g';
						a[i-1][j] = 1;
					}
					if (i+1<m){
						gro[i+1][j] = 'g';
						a[i+1][j] = 1;
					}
					if (j-1>=0){
						gro[i][j - 1] = 'g';
						a[i][j-1] = 1;
					}
					if (j + 1<n){
						gro[i][j + 1] = 'g';
						a[i][j+1] = 1;
					}
				} 
			}
		}
		x--; 
	}
	for(i = 0;i<m;i++){
		for(j = 0;j<n;j++){
			printf("%c",gro[i][j]);
		}
	} 
	return 0;
 } 
