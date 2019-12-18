#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int l;
    scanf("%d",&l);
    char a[l+1];	    
    gets(a);		//输入字符串a
    int b[26]={0},i;	        	//数组b的26个变量分别对应26个字母

    for(i=0;i<l;i++) 		
    	b[a[i]-'a']++;   	//统计字符串中各字母出现的次数
    int k=0; 		//统计出现次数为奇数的字母个数
    for(i=0;i<26;i++)
    	if(b[i]%2!=0)            k++;

    if(k>=2) 		//若存在2个及以上次数为奇数的字母
    {   printf("Impossible");
        exit(0);
    }
        else
    {   int h=0,g=l,m=0;       	//h计形成回文所需次数，m计奇数字符串时，奇数字母到达中点位置所需次数，g是每次交换长度
        for(i=0;i<(l+1)/2;i++)
        {  int j;
           for(j=g-1;j>i;j--)		 //查找是否存在不同位置的相同字母
            {   if(a[i]==a[j])		 //存在
                {   while(j<g-1)		 //交换至对应位置
                    {   char t;
                        t=a[j];
                        a[j]=a[j+1];
                        a[j+1]=t;
                        j++;     h++;		//记录次数
                    }
                    g--;
                    break;
                }
            }                      
        if(j==i)    m=(l-1)/2-i; 		//不存在，则为奇数字母
        }
        printf("%d",h+m);
    }
    return 0;
}
