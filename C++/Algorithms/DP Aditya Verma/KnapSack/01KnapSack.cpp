#include<bits/stdc++.h>
using namespace std;

/*
Recursive code  : - 
*/

int _recur(vector<int>& val, vector<int>& w, int W, int n)
{
    if(W == 0 || n == 0)    return 0;
    if(w[n-1] > W)
        return _recur(val,w,W,n-1);
    if(w[n-1] <= W)
    {
        int op1 = val[n-1] + _recur(val,w,W-w[n-1],n-1);
        int op2 = _recur(val,w,W,n-1);
        return max(op1,op2);
    }
}

/*
Memoization code :-
*/

int dp[1003][1003];
int memoize(vector<int>& val,vector<int>& w, int W, int n)
{
    if(n == 0 || W == 0)
        return 0;
    if(dp[n][W] != -1)
        return dp[n][W];
    if(w[n-1] > W)
        return dp[n][W] = _recur(val,w,W,n-1);
    if(w[n-1] <= W)
    {
        int op1 = val[n-1] + _recur(val,w,W-w[n-1],n-1);
        int op2 = _recur(val,w,W,n-1);
        return dp[n][W] = max(op1,op2);
    }
}

int iterative(vector<int>& val, vector<int>& w, int W, int n)
{
    int t[n+1][W+1];
    memset(t,INT_MIN,sizeof(t));
    for(int i = 0 ;  i <= W ; i++)
        t[0][i] = 0;
    for(int i = 0 ; i <= n ; i++)
        t[i][0] = 0;
    for(int i = 1 ; i<= n ; i++)
    {
        for(int j = 1 ; j <= W ;j++)
        {
            dp[i][j] = max(dp[i-1][j],dp[i][j]);
            if(j >= w[i-1])
            {
                dp[i][j] = max(dp[i-1][j-w[i-1]]+val[i-1],dp[i][j]);
            }
        }
    }
    return dp[n][W];
}