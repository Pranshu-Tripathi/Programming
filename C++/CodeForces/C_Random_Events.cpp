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
    int a[n+1];
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    vector<pair<int,long double>> p(m);
    for(int i = 0 ; i < m ; i++)
        cin >> p[i].first >> p[i].second;

    int lst = 0;
    for(int i = n ; i > 0 ; i--)
    {
        if(a[i] != i)
        {
            lst = i;
            break;
        }
    }
    //cout << lst << endl;
    
    long double ans = 1;
    if(lst == 0)
    {
        cout << ans << endl;
        return;
    }
    for(int i = 0 ; i < m ; i++)
    {
        if(p[i].first >= lst)
        {
            ans *= (1-p[i].second);
        }
    }

    ans = 1 - ans;
    cout.precision(20);
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
