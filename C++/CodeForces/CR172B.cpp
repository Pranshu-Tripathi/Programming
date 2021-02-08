#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    ll x,y,n;
    ll A,B;
    cin >> x >> y >> n;
    long double diff = 30001;
    for(int b = 1 ; b <= n ; b++)
    {
        ll a1 = floor((double)(x*b)/(double)y);
        ll a2 = ceil((double)(x*b)/(double)y);
        if(a1  < 0)
            a1 = 1;
        if(a2 < 0)
            a2 = 1;
        double d1 = (double)x/(double)y;
        double d2 = (double)a1/(double)b;
        double d3 = (double)a2/(double)b;
        if(diff > abs(d1-d2))
        {
            cout.precision(10);
            //cout << diff << ' ' << d1 << ' ' << d2  << ' ' << a1 << ' ' << b << endl;
            A =a1;
            B = b;
            diff = abs(d1-d2);
        }

        if(diff > abs(d1-d3))
        {
            cout.precision(10);
            //cout << diff << ' ' << d1 << ' ' << d2  << ' ' << a1 << ' ' << b << endl;
            A =a2;
            B = b;
            diff = abs(d1-d3);
        }
    }
    // cout << diff << endl;
    cout << A << '/' << B ;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
