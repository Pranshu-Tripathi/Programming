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

int query(int l , int r)
{
    ll ans = -1;
    if(l >= r)
        return -1;
    else
    {
        cout << "? " << l << ' ' << r << endl;
        cout.flush();
        cin >> ans;
    }
    return ans;
}

void answer(int ans)
{
    cout << '!' << ' ' << ans << endl;
    cout.flush();
}

void _run()
{    
    int n;
    cin >> n;
    int l = 1;
    int r = n;
    int hint1,hint2,hint3;
    while(l < r -1)
    {   
        hint1 = query(l,r);
        int mid = (l+r)/2;
        if(hint1 < mid)
        {
            hint2 = query(l,mid);
            if(hint2 == hint1)
                r = mid;
            else
                l = mid;
        }
        else
        {
            hint2 = query(mid,r);
            if(hint2 == hint1)
                l = mid;
            else
                r = mid;
        }
    }
 
    hint1 = query(l,r);
    if(l == hint1)
        answer(r);
    else
        answer(l);
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
