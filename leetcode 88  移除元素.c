void aremove(int *a, int value){
	int *p = a;
	int *q = a;
	while (*p != value){
		p++;
		q++;
	}
	int i = q - a;
	printf("%d\n", i);
	for (; i < 11; i++){
		if (*p == value){
			p++;
		}
		else{
			*q = *p;
			q++;
			p++;
		}
	}
}
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 2, 3, 4, 2, 3, 4 };
	aremove(a, 2);
	int i = 0;


	for (i = 0; i < 11; i++){
		printf("%d ", a[i]);
	}

	system("pause");
	return 0;
}
