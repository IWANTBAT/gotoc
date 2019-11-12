#include<stdio.h>
#include<math.h>
int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int str[n][m];
	long a[50000];
	int count = 0;
	int s = 0;
	for(i = 0;i<n;i++){
		for(j = 0;j<m;j++){
			scanf("%d",&str[i][j]);
		}
	}
	for(i = 0;i<n;i++){
		long sum = 0;
		for(j = m-1;j>=0;j--){
			sum = sum + str[i][j] * pow(2,abs(j-(m-1)));
		}
		a[i] = sum;
	}
	/*for(i = 0;i<n;i++){
		printf("%d  ",a[i]);
	}*/
	for(i = 0;i<m;i++){
		s = s + pow(2,i);
	}
	for(i = 0;i<n;i++){
		long sum = 0;
		for(j = m-1;j>=0;j--){
			sum = sum + str[i][j] * pow(2,abs(j-(m-1)));
		}
		int x = a[i] ^ s;
		for(j = i+1;j<n;j++){
			if(x == a[j]){
				count++;
			}
		}
	}
	printf("%d",count);
	return 0;
 } 

