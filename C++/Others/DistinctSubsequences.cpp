/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
(i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It's guaranteed the answer fits on a 32-bit signed integer.
*/

#include<bits/stdc++.h>
using namespace std;

void _run()
{
    string A,B;
    cin >> A >> B;
    int n = A.size();
    int m = B.size();

    int dp[m+1][n+1];

    memset(dp,0,sizeof(dp));

    for(int i = 1 ; i <= n ; i++)
    {
        if(B[0] == A[i-1])
            dp[1][i] = dp[1][i-1] + 1;
        else
            dp[1][i] = dp[1][i-1];
    }

    for(int i = 2 ; i <= m ; i ++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(B[i-1] == A[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            else
                dp[i][j] = dp[i][j-1];
        }
    }
    cout << dp[m][n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    _run();

    return 0;
}