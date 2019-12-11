int main()
{
    int ia[6][9],i=0,j=0; up=0,dw=5,le=0,ri=8, max=54;
    while(max)
    {
	while(i<dw && max!=0) {printf("%d ",a[i][j]);i++;max--;}
	le++;
        while(j<ri && max!=0)  {printf("%d ",a[i][j]);j++;max--;}
	dw--; 
	while(i>up && max!=0) {printf("%d ",a[i][j]);i--;max--;}
	ri--;
	while(j>le && max!=0) {printf("%d ",a[i][j]);j--;max--;}
	up++;
    }
    return 0;
}

