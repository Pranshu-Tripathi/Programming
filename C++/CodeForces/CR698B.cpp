#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


bool isluck(ll n, int d)
{
    if(n < 0)   return false;
    while(n)
    {
        if(n%10 == d)
            return true;
        n/=10;
    }

    return false;
}

void _run()
{
    int n,d;
    cin >> n >> d;
    ll a[n];
    for(int i = 0 ; i  < n ; i ++)
    {
        cin >> a[i];
    }

    for(int i =0 ; i < n ; i ++)
    {
        if(a[i] > 89)
        {
            cout << "YES" << endl;
        }
        else
        {
            bool res = false;
            while(a[i] > 0)
            {
                if(isluck(a[i],d))
                {
                    cout << "YES" << endl;
                    res = true;
                    break;
                }
                a[i] -= d;
            }   
            if(!res)
                cout << "NO" << endl;
        }
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
