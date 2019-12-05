#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
 
    int rest = num % 8;          //rest用来保留最后一位
    while (num / 8 != 0)
    {
        num = num / 8;
        putchar(num + '0');      //以ascii码的形式打印
    }
    putchar(rest + '0');
 
    return 0;
}
