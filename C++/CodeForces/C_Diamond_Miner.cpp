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


long double dist(ll x,ll y)
{
    return sqrt(x*x+y*y);
}

void _run()
{    
    int n;
    cin >> n;
    vector<ll> x;
    vector<ll> y;
    ll X,Y;
    for(int i = 0 ; i < 2 * n ; i++)
    {
        cin >> X >> Y;
        if(X == 0)
            y.push_back(abs(Y));
        if(Y == 0)
            x.push_back(abs(X));
    }

    sort(x.begin(),x.end());
    sort(y.begin(),y.end(),greater<ll> ());

    long double sum1  = 0;
    long double sum2 = 0;
    
    for(int i = 0 ; i < y.size() ; i++)
    {
        sum1 += dist(x[i],y[i]);
    }

    for(int i = 0 ; i < y.size() ; i++)
    {
        sum2 += dist(x[i],y[y.size() - 1 - i]);
    }

    long double t = min(sum1,sum2);
    cout.precision(20);
    cout << t << endl;
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
