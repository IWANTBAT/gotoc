#include<stdio.h>
#include<math.h>
int main()
{
	int a[10] = {1,0,0,1,0,1,1,0,0,0};
	int i = 0;
	int sum = 0;
	for(i = 9;i>=0;i--)
	{
		sum = sum + a[i] * pow(2,abs(i-9));
	}
	printf("%d\n",sum);
	return 0;
 } 
