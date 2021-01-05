#include<bits/stdc++.h>
using namespace std;

void _run()
{
    string s;
    cin >> s;

    int dp[s.size()][s.size()];

    for(int i = 0 ; i < s.size() ; i++)
        for(int j = 0 ; j < s.size() ; j++)
        {
            if(i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    
    for(int leng = 2 ; leng <= s.size() ; leng++)
    {
        for(int i = 0 ; i < s.size() - leng + 1 ; i++)
        {
            int j = i + leng - 1;
            if(s[i] == s[j] && leng == 2)
                dp[i][j] = 2;
            else if(s[i] == s[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
        }
    }

    cout << dp[0][s.size() - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    _run();

    return 0;
}