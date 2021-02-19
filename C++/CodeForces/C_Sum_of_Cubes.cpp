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
    ll x;
    cin>>x;
    vector<ll> cubes;
    ll ind=1;
    while(1)
    {
        if(ind*ind*ind >= 1000000000000)
        {
            break;
        }
        cubes.push_back(ind*ind*ind);
        ind++;
    }
    int l=0, r=cubes.size()-1;
    while(l <= r)
    {
        ll sum = cubes[l]+cubes[r];
        if(sum==x || cubes[l]*2==x || cubes[r]*2==x)
        {
            cy;
            return;
        }
        else if(sum > x)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    cn;

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
