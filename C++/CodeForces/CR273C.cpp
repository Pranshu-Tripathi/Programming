#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(false); \
                    cin.tie(NULL);

void _run()
{
    ll r,g,b;
    cin >> r >> g >> b;
    ll ma = max(r,max(g,b));
    if(ma >= 2*(r+g+b-ma))
    {
        cout << r+g+b-ma<<endl;
    }
    else
    {
        cout << (r+g+b)/3 << endl;
    }
}

int main()
{
    fast;
    int test = 1;
    while(test--)
        _run();
    return 0;
}