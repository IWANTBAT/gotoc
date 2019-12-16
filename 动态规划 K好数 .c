#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int k,l;
	cin>>k>>l;
	long long table[100][100];
	for(int i=0;i<k;i++)
	{  table[0][i]=1ll;
	}
	table[0][0]=0ll;
	for(int i=1;i<l;i++)
	{  	for(int j=0;j<k;j++)
		{
			long long  x=0;
			for(int y=0;y<k;y++)
			{
				if(y!=j+1 && y!=j-1)
				{
					x+=table[i-1][y];
				}
			}
			table[i][j]=x%1000000007ll;
		}
	}
	long long count=0;
	for(int i=0;i<k;i++)
	{
		count+=table[l-1][i];
	}
	cout<<(count%1000000007ll);
	return 0;
}

