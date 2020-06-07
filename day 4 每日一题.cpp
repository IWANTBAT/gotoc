//牛客网  不要二
#include<stdio.h>

int main()
{
	int w, h, result = 0, i, j;
	scanf("%d %d", &w, &h);
	for (i = 0; i<w; i++){
		for (j = 0; j<h; j++){
			if (i % 4<2 && j % 4<2 || i % 4>1 && j % 4<4 && j % 4>1 && j % 4<4)
				result++;
		}
	}
	printf("%d", result);
	return 0;
}
