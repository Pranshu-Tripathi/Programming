#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n;
    cin >> n;
    long long a[n];
    int h = 0;
    int v = 0;
    int dp[n] = {0};
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(i >= 1 && i < n-1)
        {
            if(a[i-1] > a[i] && a[i+1] > a[i])
                dp[i] = -1,v++;
            else if(a[i-1] < a[i] && a[i+1] < a[i])
                dp[i] = 1,h++;
        }
    }

    if(h == 0 && v == 0)
    {
        cout << 0 << endl;
        return;
    }

    // for(int i = 0 ; i < n ; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    int hvh = -1;
    int vhv = -1;
    for(int i = 1 ; i < n-3 ; i++)
    {
        if(dp[i] == 1 && dp[i+1] == -1 && dp[i+2] == 1)
        {
            hvh=(i);
            break;
        }
        else if(dp[i] == -1 && dp[i+1] == 1 && dp[i+1] == -1)
        {
            vhv=(i);
            break;
        }
    }
    if(hvh > 0 || vhv > 0)
    {
        cout << h + v - 3  << endl;
        return;
    }

    int hv = -1;
    int vh = -1;

    for(int i = 1 ; i < n-2 ; i++)
    {
        if(dp[i] == 1 && dp[i-1] == -1)
        {
            hv = i;
            break;
        }
        else if(dp[i] == -1 && dp[i+1] == 1)
        {
            vh = i;
            break;
        }
    }
    
    if(hv >0 || vh > 0)
    {
        // if(hv > 0)
        // {
        //     if(dp[hv] < dp[hv+2])
        //     {
        //         cout << h + v - 1 << endl;
        //         return;
        //     } 
        //     else
        //     {
        //         cout << h + v - 2 << endl;
        //         return;
        //     } 
        cout << h + v - 2  << endl;
        return;
        
        // else
        // {
        //     if(dp[vh] < dp[vh+2])
        // }
        
    }

    cout << h + v - 1  << endl;
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
