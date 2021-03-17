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

    hint1 = query(l,r);
    if(hint1 == 1 || query(l,hint1) != hint1)
    {
        int l = hint1,r = n;
        while(l < r - 1)
        {
            int mid = (l+r)/2;
            hint2 = query(hint1,mid);
            if(hint2 == hint1)
                r = mid;
            else
                l = mid;
        }
        answer(r);
    }
    else
    {
        l = 1;
        r = hint1;
        while(l < r - 1)
        {
            int mid = (l+r)/2;
            hint2 = query(mid,hint1);
            if(hint2 ==  hint1)
                l = mid;
            else
                r = mid;
        }
        answer(l);
    }
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
