#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n,k;
    cin >> n >> k;
    vector<int> height(n);
    for(int i = 0 ; i < n ; i++)
        cin >> height[i];
    sort(height.begin(),height.end());
    vector<vector<int>> dp1(n,vector<int>(k + 1,0));
    vector<int> tower1;
    vector<int> tower1Ind;
    vector<int> tower2;

    for(int i = 0; i < n ; i++)
        dp1[i][0] = 0;
    
    for(int i = 1; i <= k ;i ++)
    {
        if(height[0] >= i)
            dp1[0][i] = 1;
        else
            dp1[0][i] = -1;
    }

    // for(int i =0 ; i < n ; i++)
    // {
    //     for(int j = 0 ; j <= k ; j++)
    //     {
    //         cout << dp1[i][j] << ' '; 
    //     }
    //     cout << endl;
    // }

    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j <= k ; j++)
        {
            if(j <= height[i])
            {
                dp1[i][j] = 1;
                continue;
            }
            
            int opt1 = dp1[i-1][j];
            int opt2 = dp1[i-1][j-height[i]];

            if(opt1 == -1 && opt2 == -1)
            {
                dp1[i][j] = -1;
                continue;
            }
            if(opt1 == -1)
            {
                dp1[i][j] = opt2 + 1;
                continue; 
            }
            if(opt2 == -1)
            {
                dp1[i][j] = opt1;
                continue;
            }

            dp1[i][j] = min(opt1,opt2+1);
        }
    }
    int ans = dp1[n-1][k];
    if(ans == -1)
    {
        cout << -1 << endl;
        return;
    }
    int start,en;
    for(int i = 0 ; i < n ; i++)
    {
        if(ans == dp1[i][k])
        {
            start = i, en = k;
            break;
        }
    }

    // for(int i =0 ; i < n ; i++)
    // {
    //     for(int j = 0 ; j <= k ; j++)
    //     {
    //         cout << dp1[i][j] << ' '; 
    //     }
    //     cout << endl;
    // }

    // cout << start << " " << en << endl;
    tower1.push_back(height[start]);
    tower1Ind.push_back(start);
    while(start > 0 && en > 0)
    {
        if(dp1[start][en] <= 0)
            break;
        en = en - height[start];
        if(en < 0)  break;
        int val = dp1[start-1][en];
        if(val <= 0)    break;
        int x;
        for(int i = 0 ;i < start ; i++)
            if(dp1[i][en] == val)
            {
                x = i;
                break;
            }
        start = x;
        tower1.push_back(height[start]);
        tower1Ind.push_back(start);
        // cout << start << " " << en << endl;
    }
    // for(auto x : tower1)
    //     cout << x << ' ';
    // cout << endl;
    for(auto x : tower1Ind)
    {
        height.erase(height.begin() + x);
    }
    if(height.size() == 0)
    {
        cout << -1 << endl;
        return;
    }
    sort(height.begin(),height.end());

    // for(auto x : height)
    //     cout << x << ' ';
    cout << endl;
    n = height.size();
    //cout << "DP@" << endl;
    vector<vector<int>> dp2(height.size(),vector<int>(k+1));

    for(int i = 0; i < n ; i++)
        dp2[i][0] = 0;
    
    for(int i = 1; i <= k ;i ++)
    {
        if(height[0] >= i)
            dp2[0][i] = 1;
        else
            dp2[0][i] = -1;
    }

    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j <= k ; j++)
        {
            if(j <= height[i])
            {
                dp2[i][j] = 1;
                continue;
            }
            
            int opt1 = dp2[i-1][j];
            int opt2 = dp2[i-1][j-height[i]];

            if(opt1 == -1 && opt2 == -1)
            {
                dp2[i][j] = -1;
                continue;
            }
            if(opt1 == -1)
            {
                dp2[i][j] = opt2 + 1;
                continue; 
            }
            if(opt2 == -1)
            {
                dp2[i][j] = opt1;
                continue;
            }

            dp2[i][j] = min(opt1,opt2+1);
        }
    }

    // for(int i =0 ; i < n ; i++)
    // {
    //     for(int j = 0 ; j <= k ; j++)
    //     {
    //         cout << dp2[i][j] << ' '; 
    //     }
    //     cout << endl;
    // }

    ans = dp2[n-1][k];
    if(ans == -1)
    {
        cout << -1 << endl;
        return;
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(ans == dp2[i][k])
        {
            start = i, en = k;
            break;
        }
    }

    // cout << start << " " << en << endl;
    tower2.push_back(height[start]);
    while(start > 0 && en > 0)
    {
        if(dp2[start][en] <= 0)
            break;
        en = en - height[start];
        if(en < 0)  break;
        int val = dp2[start-1][en];
        if(val <= 0)    break;
        int x;
        for(int i = 0 ;i < start ; i++)
            if(dp2[i][en] == val)
            {
                x = i;
                break;
            }
        start = x;
        tower2.push_back(height[start]);
        // cout << start << " " << en << endl;
    }    

    // for(auto x : tower2)
    //     cout << x << ' ';
    // cout << endl;

    cout << tower1.size() + tower2.size() << endl;
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
