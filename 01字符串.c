#include<stdio.h>
int main()
{
	int i, j, k, n, m;
	for (i = 0; i<2; i++){
		for (j = 0; j<2; j++)
		   for (k = 0; k<2; k++)
		        for (n = 0; n<2; n++)
		            for (m = 0; m<2; m++)
			             printf("%d%d%d%d%d\n", i, j, k, n, m);
	}
	return 0;
}
