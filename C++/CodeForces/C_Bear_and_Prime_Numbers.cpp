#include <bits/stdc++.h>
using namespace std;
 
#define ll long
 
ll arr[10000001] = {0};
ll occur[10000001] = {0};
ll pre[10000001] = {0};
 
void sieve()
{
    ll maxN = 10000000;
    for (ll i = 2; i <= maxN; i++)
    {
        if (arr[i] == 0)
        {
            for (ll j = i; j <= maxN; j += i)
                if (arr[j] == 0)
                    arr[j] = i;
        }
    }
}
 
void cal()
{
    set<ll> s;
    ll n;
    scanf("%ld",&n);
    //cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll num;
        scanf("%ld",&num);
        //cin >> num;
        while (num > 1)
        {
            s.insert(arr[num]);
            num /= arr[num];
        }
        for (ll x : s)
        {
            occur[x]++;
        }
        s.clear();
    }
}
 
void pre_comp()
{
    pre[2] = occur[2];
    for (ll i = 3; i <= 10000000; i++)
        pre[i] = occur[i] + pre[i - 1];
}
 
void fuck()
{
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        scanf("%ld%ld", &l, &r);
        //cin >> l >> r;
        l = min(l, (ll)10000000);
        r = min(r, (ll)10000000);
        printf("%ld\n", pre[r] - pre[l - 1]);
        //cout <<  << "\n";
    }
}
 
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    sieve();
    cal();
    pre_comp();
    fuck();
}