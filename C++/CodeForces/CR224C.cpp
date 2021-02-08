#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a[0];
    bool cons = true;
    for(int i = 1 ; i < n ; i ++)
    {
        cin >> a[i];
        if(a[i] != a[i-1])
            cons = false;
    }

    sort(a.begin(),a.end());

    if(n == 1)
    {
        cout << -1 << endl;
        return;
    }
    else if(n == 2)
    {
        if(cons)
        {
            cout << 1 << endl;
            cout << a[0];
        }
        else if((a[1] - a[0])% 2 == 0)
        {
            cout << 3 << endl;
            ll r = a[1] - a[0];
            cout << a[0] - r << ' ' << a[0] + r/2 << ' ' <<  a[1] + r << endl;
        }
        else
        {
            cout << 2 << endl;
            ll r = a[1] - a[0];
            cout << a[0] -  r << ' ' << a[1] + r << endl;
        }
        return;
    }

    if(cons)
    {
        cout << 1 << endl;
        cout << a[0] ;
        return;
    }

    ll r = a[1] - a[0];
    bool betweenone = true;
    for(int i = 2 ; i < n ; i ++)
    {
        if(a[i] - a[i-1] != r / 2)
            betweenone = false;
    }

    if(betweenone)
    {
        cout << 1 << endl;
        cout << a[0]+ r/2 << endl;
        return;
    }
    set<ll> possi;
    bool doubleR = false;
    bool halfR = false;
    for(int i = 2 ; i < n ; i ++)
    {
        if(a[i] - a[i-1] != r)
        {
            if(a[i] - a[i-1] == 2 * r && !doubleR)
            {
                possi.insert(a[i] - r);
                doubleR = true;
            }
            else
            {
                cout << 0 << endl;
                return;
            }
        }
    }

    if(doubleR)
    {
        cout << 1 << endl;
        for(ll i : possi)
            cout << i;
        return;
    }

    

    possi.insert(a[0] - r);
    possi.insert(a[n-1] + r);

    cout << possi.size() << endl;
    for(ll i : possi)
        cout <<  i << ' ';

}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
