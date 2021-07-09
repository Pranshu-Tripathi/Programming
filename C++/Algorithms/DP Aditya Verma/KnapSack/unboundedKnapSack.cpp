#include<bits/stdc++.h>
using namespace std;

/*
Bounded KnapSack -> either ways wether we include a item or we do not include a item, the item is considered 
to be processed

Unbounded KnapSack -> 
if we don't consider the element in solution then it is processed.
if we are including the element in our solution then it can be processed again
*/

int iterative(vector<int>& val, vector<int>& w, int W, int n)
{
    int dp[n+1][W+1];
    memset(dp,0,sizeof(dp));
    for(int i = 1 ; i <= n;  i++)
    {
        for(int j = 1 ; j <= W ; j++)
        {
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
            if(w[i-1] <= j)
                dp[i][j] = max(dp[i-1][j] , dp[i][j-w[i-1]]+ val[i-1]);
        }
    }
}