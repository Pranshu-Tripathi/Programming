#include<bits/stdc++.h>
using namespace std;


int iterative(vector<int>& length, vector<int>& price, int n, int possLength)
{
    int dp[n+1][possLength+1];
    memset(dp,0,sizeof(dp));
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= possLength ; j++)
        {
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
            if(length[i-1] <= j)
            {
                dp[i][j] = max(dp[i][j],dp[i][j-length[i-1]]+ price[i-1]);
            }
        }
    }
}