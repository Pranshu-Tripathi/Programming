/*
Get maximum profit from elements of given weights and profits for given limit weight.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n,k;
    cin >> n >> k;
    vector<int> weight(n);
    vector<int> profit(n);
    for(int i = 0 ; i < n ; i++)
        cin >> weight[i];
    for(int i = 0 ; i < n ; i++)
        cin >> profit[i];
    
    int dp[n][k+1];

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j <= k ; j++)
            dp[i][j] = 0;
    
    for(int i =0 ; i <= k ; i++)
    {
        if(i >= weight[0])
            dp[0][i] = profit[0];
    }

    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j <= k ; j ++)
        {
            if(weight[i] > j)
                dp[i][j] = dp[i-1][j];
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+profit[i]);
            }
        }
    }
    
    cout << dp[n-1][k] << endl;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
