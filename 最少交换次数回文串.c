#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int l;
    scanf("%d",&l);
    char a[l+1];	    
    gets(a);		//�����ַ���a
    int b[26]={0},i;	        	//����b��26�������ֱ��Ӧ26����ĸ

    for(i=0;i<l;i++) 		
    	b[a[i]-'a']++;   	//ͳ���ַ����и���ĸ���ֵĴ���
    int k=0; 		//ͳ�Ƴ��ִ���Ϊ��������ĸ����
    for(i=0;i<26;i++)
    	if(b[i]%2!=0)            k++;

    if(k>=2) 		//������2�������ϴ���Ϊ��������ĸ
    {   printf("Impossible");
        exit(0);
    }
        else
    {   int h=0,g=l,m=0;       	//h���γɻ������������m�������ַ���ʱ��������ĸ�����е�λ�����������g��ÿ�ν�������
        for(i=0;i<(l+1)/2;i++)
        {  int j;
           for(j=g-1;j>i;j--)		 //�����Ƿ���ڲ�ͬλ�õ���ͬ��ĸ
            {   if(a[i]==a[j])		 //����
                {   while(j<g-1)		 //��������Ӧλ��
                    {   char t;
                        t=a[j];
                        a[j]=a[j+1];
                        a[j+1]=t;
                        j++;     h++;		//��¼����
                    }
                    g--;
                    break;
                }
            }                      
        if(j==i)    m=(l-1)/2-i; 		//�����ڣ���Ϊ������ĸ
        }
        printf("%d",h+m);
    }
    return 0;
}
