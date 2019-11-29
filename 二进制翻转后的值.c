#include<stdio.h>
#include<windows.h>
#include<math.h>
#pragma warning(disable:4996)
unsigned int reverse_bit(unsigned int value){
	int i = 0;
	int sum = 0;
	for (i = 0; i < 32; i++){
		int r = ((value >> i) & 1) * pow(2, 31 - i);
		sum += r;
	}
	return sum;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int a = reverse_bit(n);
	printf("%u\n", a);
	system("pause");
	return 0;
}
