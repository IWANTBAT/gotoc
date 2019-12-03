#include<stdio.h>

int main(){
	int a[10000] = {1};
	int n = 0;
	int i,k;
	int jw = 0;
	int d = 0;
	int s = 0;
	scanf("%d",&n);
	for(i = 2;i<=n;i++){
		for(k = 0;k<=d;k++){
			s = a[k] * i + jw;
			a[k] = s%10;
			jw = s/10;
		}
		while(jw){
			a[k] = jw%10;
			jw /= 10;
			k++;
		}
		d = k-1;
	}
	for(i = d;i>=0;i--){
		printf("%d",a[i]);
	}
	return 0;
} 
