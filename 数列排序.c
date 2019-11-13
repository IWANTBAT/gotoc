#include<stdio.h>
void InsertSort(int a[], int n)
{
    int i, j;
    int temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (temp < a[j])
            {
                a[j + 1] =a[j];
            }
            else
            {
                break;
            }
        }
        a[j + 1] = temp;
    }
}
int main()
{
	 int n,i,j;
	 scanf("%d",&n);
	 int a[n];
	 for(i = 0;i<n;i++)
	 {
	 	scanf("%d",&a[i]);
	 }
	 InsertSort(a,n);
	 for(i = 0;i<n;i++) 
	 printf("%d\t",a[i]);
	return 0;
	
}
