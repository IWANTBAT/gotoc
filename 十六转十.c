#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int lengh,i;
	long long sum = 0;
	char a[100];
	scanf("%s",&a);
	lengh = strlen(a);
	for(i = 0;i<lengh;i++){
		if(a[i] >= '0'&&a[i] <='9'){
			sum +=(a[i] - '0') * pow(16*1.0 , lengh-1-i); 
		}
		else{
			sum +=(a[i] -'A' + 10) *pow(16*1.0,lengh-1-i);
		}
	}
	printf("%lld",sum);
	return 0;
}
