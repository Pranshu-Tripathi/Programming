/*
PR7
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000009
#define debug(a...) cout<<#a<<": ";for(auto it:a)cout<<it<<" ";cout<<endl;


bool manhatton(int x1,int y1, int x2, int y2, int k)
{
    return abs(x1-x2) + abs(y1-y2) <= k;
}

void _run()
{    
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> pts(n);
    for(int i = 0 ; i < n ; i++)
        cin >> pts[i].first >> pts[i].second;
    int dp[n];
    memset(dp,0,sizeof(dp));

    for(int i = 0 ; i < n ; i++)
    {
        int v = 0;
        for(int j = 0 ; j < n ; j++)
        {
            if(manhatton(pts[i].first,pts[i].second,pts[j].first,pts[j].second,k))
            {
                v++;
            }
        }
        dp[i] = v;
    }
    //debug(dp);
    for(int i = 0 ; i < n ; i++)
    {
        if(dp[i] == n)
        {
            cout << 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    fast;
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
