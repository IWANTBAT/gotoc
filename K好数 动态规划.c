#include<stdio.h>


int main()
{
	long long s[100][100] = {0};
	int k, l;
	scanf("%d%d", &k, &l);
	int i = 0;
	int j = 0;
	for (j = 1; j < k; j++){

		s[0][j] = 1;
	}
	for (i = 1; i < l; i++){
		for (j = 0; j < k; j++){
			int y = 0;
			long long x = 0;
			for (y = 0; y < k; y++){
				if (y != j - 1 && y != j + 1){
					x += s[i - 1][y];
				}
			}
			s[i][j] = (s[i][j] + x) % 1000000007;
		}
	}
	long long count = 0;
	for (i = 0; i < k; i++){
		count += s[l - 1][i];
	}
	count = count % 1000000007;
	printf("%I64d\n", count);
	return 0;
}
