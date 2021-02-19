#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double

void _run()
{
    ll n , k ;
    cin >> n >> k;

    if(n % 2 == 0)
    {
        if(k % n == 0)
        {
            cout << n << endl;
        }
        else
        {
            cout << k % n << endl;
        }
    }   
    else
    {
        ll pos = n/2+1;
        ll jump = n/2;
        ll it = 1;
        if(k <= n/2)
        {
            cout << k << endl;
            return;
        }
        if(k == pos)
        {
            cout << pos+1 << endl;
            return;
        }
        it = (k - pos)/jump + 1;
        ll ori = (k%n);
        if(ori == 0)
            ori = n;
        ll catB = (ori + it) % n;
        if(catB == 0)
            catB = n;
        
        cout << catB  << endl; 
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
