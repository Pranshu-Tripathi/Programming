#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool _sortbysec(const pair<int,int>& a ,const pair<int,int>& b)
{
        return (a.second < b.second);
}

void _run()
{
    int n;
    cin >> n;
    vector<pair<int,int>> inp(n);
    for(int  i = 0 ; i < n ; i++)
        cin >> inp[i].first >> inp[i].second;
    
    sort(inp.begin(),inp.end(),_sortbysec);

    int points = 0;
    vector<int> laterUse;
    int count = 1;
    for(int i = 0; i < n ; i++)
    {
        if(inp[i].second != 0)
        {
            count += inp[i].second - 1;
            points += inp[i].first;
        }
        else
        {
            laterUse.push_back(inp[i].first);
        }
    }

    if(count == 1 || laterUse.size() == 0)
    {
        if(laterUse.size() != 0)
            points += *max_element(laterUse.begin(),laterUse.end());
        cout << points << endl;
        return;
    }

    // cout << points  << ' ' <<count << endl;
    
    // for (auto z : laterUse)
    //     cout << z << ' ';
    // cout << endl;

    int dp[laterUse.size()][count+1];
    memset(dp,0,sizeof(dp));

    for(int i = 1 ; i <= count ; i++)
            dp[0][i] = laterUse[0];

    for(int i = 1 ; i < laterUse.size() ; i++)
    {
        for(int j = 1 ; j <= count ; j++)
        {
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1] + laterUse[i]);
        }
    }

    // for(int i = 0 ; i < laterUse.size() ; i++)
    // {
    //     for(int j = 0 ; j <= count ; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    points += dp[laterUse.size()-1][count];
    cout << endl << points << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test= 1;
    while(test--)
        _run();
    return 0;
}