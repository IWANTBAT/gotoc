//删除第一个字符串中出现的左右第二个字符串中的字符
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int main()
{
	char str1[100] = "welcome to xian";
	char str2[100] = "eon";
	//scanf("%s", &str1);
	//scanf("%s", &str2);
	char* fast = str1;
	char* slow = str1;
	char* str = str2;
	while (*str){
		fast = slow = str1;
		while (*fast){
			if ((*fast) == (*str)){
				fast++;
			}
			else{
				*slow = *fast;
				fast++;
				slow++;
			}
		}
		str++;
	}
	*(slow++) = '\0';
	printf("%s\n", str1);
	return 0;
}


//组队竞赛
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int main(){
	int n, t, i, j;

	scanf("%d", &n);
	int *a = (int*)malloc(sizeof(int)* 3 * n);
	i = 0;
	for (i; i < 3 * n - 1; i++){
		scanf("%d ", &a[i]);

	}
	int a[] = { 5, 2, 8, 5, 1, 5 };
	for (i = 0; i<3 * n - 1; i++){
		for (j = 0; j<3 * n - i - 1; j++){
			if (a[j]>a[j + 1]){
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	long long sum = 0;
	i = n;
	for (; i <= 3 * n - 2; i += 2){
		sum += a[i];
	}
	printf("%lld\n", sum);
	return 0;
}
