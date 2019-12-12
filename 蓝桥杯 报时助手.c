#include<stdio.h>

char *st[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven", "twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty", "thirty","forty","fifty"};

void change(int num);
int main()
{
    int h,m;
    scanf("%d%d",&h,&m);
    if(m==0)
    {
	change(h);
	printf("o'clock\n");
    }
    else
    {
	change(h);
	change(m);
	printf("\n");
    }
    return 0;
}
void change(int num)
{
	int a,b;
	a=num/10;
	b=num%10;
	if(num<=20)
	    printf("%s ",st[num]);
	else
	{
	    printf("%s ",st[a+18]);
	    if(b)
		printf("%s ",st[b]);
	}
}
