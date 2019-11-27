int a[100],n;
void quicksort(int left, int right) {
	int i, j, t, temp;
	if(left > right)
		return;
    temp = a[left];
    i = left;
    j = right;
    while(i != j) {
    	while(a[j] >= temp && i < j)
    		j--;
    	while(a[i] <= temp && i < j)
            i++;
    	if(i < j)
    	{
    		t = a[i];
    		a[i] = a[j];
    		a[j] = t;
    	}
    }
    a[left] = a[i];
    a[i] = temp;
    quicksort(left, i-1);
    quicksort(i+1, right);
}

int main()
{
	int i,n;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
    scanf("%d", &a[i]);
       quicksort(1, n);
      	printf("最小的数为：%d ", a[1]);
    	printf("较小的数为：%d ", a[2]);
        printf("较大的数为：%d ", a[n-1]);
        printf("最大的数为：%d ", a[n]);
    return 0;
}

