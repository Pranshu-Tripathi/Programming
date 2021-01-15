#include<bits/stdc++.h>
using namespace std;
#define ll long long

void _run()
{
    int n,m;
    cin >> n >> m;
    int tvs[n];
    for(int i = 0 ; i < n ; i++)   
        cin >> tvs[i];
    
    vector<int> usefultvs;
    for(int i = 0 ;i < n ; i++)
        if(tvs[i] < 0)
            usefultvs.push_back(-tvs[i]);
    
    if(usefultvs.size() == 0)
    {
        cout << 0 << endl;
        return;
    }

    int z = usefultvs.size();

    int dp[z][m+1];

    memset(dp,0,sizeof(dp));

    for(int i = 1 ; i <= m ; i++)
        dp[0][i] = usefultvs[0];

    for(int i = 1 ; i < z ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            dp[i][j] = max(dp[i-1][j-1] + usefultvs[i],dp[i-1][j]);
        }
    }
    cout << dp[z-1][m] << endl;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1;
    while(test--)
        _run();
    return 0;
}