
#include<stdio.h>
int main()
{
	int a[34][34];
	int i,j,n;
	scanf("%d",&n);
	a[0][0] = 1;
	for(i = 1;i<n;i++){
		for(j = 0;j<=i;j++){
			if(j-1 >= 0){
				if(j<i){
					a[i][j] = a[i-1][j] + a[i-1][j-1];
				}
				else{
					a[i][j] = a[i-1][j-1];
				}
			}
		else{
			a[i][j] = a[i-1][j];
		}
		}
	}
	for(i = 0;i<n;i++){
		for(j = 0;j<=i;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
