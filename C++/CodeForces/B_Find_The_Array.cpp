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
    int n;
    cin >> n;
    ll a[n];    
    ll sum = 0;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i], sum += a[i];
    ll b[n];
    ll c[n];
    for(int i = 0 ; i < n ; i++)
    {
        if(i%2==0)
        {
            b[i] = a[i];
            c[i] = 1;
        }
        else
        {
            b[i] = 1;
            c[i] = a[i];
        }
    }

    ll sum1 = 0;
    ll sum2 = 0;
    for(int i = 0 ; i < n ; i++)
    {
        sum1 += abs(a[i] - b[i]);
        sum2 += abs(a[i] - c[i]);
    }

    if(sum >= sum1 * 2)
    {
        for(int i = 0 ;  i < n ; i++)
            cout << b[i] << ' ';
        cout << endl; 
    }
    else
    {
        for(int i = 0 ; i < n ; i++)
            cout << c[i] << ' ';
        cout << endl;
    }
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
