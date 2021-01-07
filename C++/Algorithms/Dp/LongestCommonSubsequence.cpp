/*
find longest common subsequences of two strings.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    string s,t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int dp[n+1][m+1] ;
    for(int i = 0 ; i <= n ; i++)
        for(int j = 0; j <= m ; j++)
            dp[i][j] = 0;
    
    for(int i = 1;  i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }


    int lcs = dp[n][m];
    vector<char> lcsStr;
    int row = n, col = m;
    while(row > 0 && col > 0)
    {
        if(dp[row][col] != dp[row-1][col] && dp[row][col] != dp[row][col-1])
        {
            lcsStr.push_back(s[row-1]);
            row--;
            col--;
        }
        else if(dp[row][col] == dp[row-1][col])
        {
            row--;
        }
        else
        {
            col--;
        }
    }

    cout << lcs << " : ";
    reverse(lcsStr.begin(),lcsStr.end());
    for(auto c : lcsStr)
        cout << c;
    
    cout << endl;
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
