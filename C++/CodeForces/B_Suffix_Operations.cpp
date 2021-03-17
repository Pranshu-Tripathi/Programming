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
    ll n;
    cin >> n;
    ll a[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    ll o[n];
    o[n-1] = 0;
    ll f_val = a[n-1];
    ll sum = 0;
    for(int i = n - 2 ; i >= 0 ; i--)
    {
        o[i] = abs(f_val - a[i]);
        f_val = a[i];
        sum += o[i];
    }
    //debug(o);
    ll moves = sum;
    ll rem = max(abs(a[0] - a[1]) , abs(a[n-1] - a[n-2]));

    for(int i = 1 ; i < n - 1 ; i++)
    {   
        rem = max(rem, abs(a[i] - a[i-1]) + abs(a[i+1] - a[i]) - abs(a[i-1] - a[i+1]));
    }

    cout << moves - rem  << endl;
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
