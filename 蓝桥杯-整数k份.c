int dp(int n,int k)
{ 
  if(k==0||n<k) return 0;
  else if(k==n) return 1;
  else return dp(n-1,k-1)+dp(n-k,k);
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d\n",dp(n,k));
	return 0;
}

