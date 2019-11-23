#include<stdio.h>
#include<math.h>
int main()
{
	int n,m,i,j;
	scanf("%d",&n);
	scanf("%d",&m);
	int a[n][m];
	for(i = 0;i<n;i++){
		for(j = 0;j<m;j++){
			a[i][j] = abs(i-j)+65;
			printf("%c",a[i][j]);
		}
		printf("\n");
	} 
	return 0;
 } 
