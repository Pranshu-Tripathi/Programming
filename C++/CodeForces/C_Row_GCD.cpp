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
    ll a[n],b[m];
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];
    sort(a,a+n);
    for(int i = 0 ; i < m ; i++)
        cin >> b[i];
    ll g = 0;
    for(int i = 1 ; i < n ; i++)
        g = __gcd(g,a[i]-a[i-1]);
    for(int i = 0 ; i < m ; i++)
    {
        cout << __gcd(g,a[0]+b[i]) << ' ';
    }
    
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
