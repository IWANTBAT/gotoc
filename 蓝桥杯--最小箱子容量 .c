int max(int x,int y)
{return x>y?x:y;}

int main()
 {  int dp[31][20001]={0};
    int v, n;
    int i,j,t;
    scanf("%d%d",&v,&n);
    for(i = 1; i <= n; i++) { 
        scanf("%d",&t);
        for(j = 1; j <= v; j++) {
            if (j >= t) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-t] + t);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("%d",v-dp[n][v]);
    return 0;
}

