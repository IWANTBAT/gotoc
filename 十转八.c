#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
 
    int rest = num % 8;          //rest�����������һλ
    while (num / 8 != 0)
    {
        num = num / 8;
        putchar(num + '0');      //��ascii�����ʽ��ӡ
    }
    putchar(rest + '0');
 
    return 0;
}
