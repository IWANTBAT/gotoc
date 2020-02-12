#include<stdio.h>
#include<string.h>

int main()
{char number[20][20] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

 char unit[20][20] = {"","","shi","bai","qian","wan","shi", "bai", "qian", "yi", "shi"};
			//根据需要扩充
 char str[100];	

 int len,hnz,i;

 scanf("%s",str);
 len=strlen(str);
	
 hnz=0;	
  for(i=0;i<len;i++)
	{int digit=str[i]-'0';
	 if(digit==0) 
		{if(hnz==1&&(len-i)%4==1)
			printf("%s ",unit[len-i]);	
		 if(i+1<len&&str[i+1]!='0')	
			printf("%s ",number[digit]);
		}
	  else
		{if(!(digit==1&&i==0&&(len-i)%4==2))	
			printf("%s ",number[digit]);
		 printf("%s ",unit[len-i]);	
		 hnz=1;
		}	
	if((len-i)%4==1) hnz=0;
	}
 return 0;
} 

