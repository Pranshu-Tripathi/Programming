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


void _run()
{    
    int n,m;
    cin >> n >> m;
    int r[n];
    int c[m];
    bool vis[101];
    memset(vis,false,sizeof(vis));
    for(int i = 0 ; i < n ; i++)
        cin >> r[i], vis[r[i]] = true;
    int ans = 0;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> c[i];
        if(vis[c[i]])
            ans++;
    }
    cout << ans << endl;
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
