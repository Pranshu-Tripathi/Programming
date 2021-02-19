#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl



void _run()
{
    ll a,b;
    cin>>a>>b;
    ll cnt = 1;
    while(a >= b)
    {
        if(a == b)
        {
            cnt++;
            break;
        }
        if(b == 1)
        {
            b++;
            cnt++;
            continue;
        }
        ll aw = b+1;
        ll te = a;
        ll cnt1 = 0;
        while(te)
        {
            te /= b;
            cnt1++;
        }
        te = a;
        ll cnt2 = 0;
        while(te)
        {
            te /= aw;
            cnt2++;
        }
        if(cnt2+1 <= cnt1)
        {
            b++;
        }
        else
        {
            a /= b;
        }
        cnt++;
    }
    cout<<cnt<<endl;

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
