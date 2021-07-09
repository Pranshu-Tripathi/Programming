#include<bits/stdc++.h>
using namespace std;


int iterative(vector<int>& coins, int sum, int n)
{
    int dp[n+1][sum+1];
    memset(dp,INT_MAX-1,sizeof(dp));
    for(int i = 0;  i <= n ; i++)
        dp[i][0] = 0;
    
    for(int i = 1 ; i <= sum ; i++)
        if(i % coins[0] == 0)
            dp[1][i] = i/coins[0];

    for(int i = 2;  i <= n ; i++)
    {
        for(int j = 1;  j <= sum ; j++)
        {
            dp[i][j] = min(dp[i][j] , dp[i-1][j]);
            if(coins[i-1] <= j)
                dp[i][j] = min(dp[i][j],dp[i][j-coins[i-1]]+1);
        }
    }
}