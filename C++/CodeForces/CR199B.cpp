#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

bool belongsto(ll s, ll l , ll r)
{
    return (s <= r && s >= l);
}

void _run()
{
    int n,m,s,f;
    cin >> n >> m >> s >> f;
    map<ll,pair<ll,ll>> stepwatch;
    for(int i  = 0 ; i < m ; i++)
    {
        ll t,l,r;
        cin >> t >> l >> r;
        stepwatch[t] = {l,r};
    }

    string move = "";
    int towardsf = 0;
    if(s < f)
        move += "R",towardsf = 1;
    else
        move += "L",towardsf = -1;
    string stay = "X";
    string ans = "";
    for(int step = 1;  ; step++)
    {
        if(s == f)
            break;
        if(stepwatch.find(step) != stepwatch.end())
        {
            // there is a watch;
            ll l = stepwatch[step].first;
            ll r = stepwatch[step].second;
            if(belongsto(s,l,r) || belongsto(s+towardsf,l,r))
            {
                ans += stay;
            }
            else
            {
                ans += move;
                s = s + towardsf;
            }
        }
        else
        {
            ans += move;
            s = s+towardsf;
        }
    }
    
    cout << ans << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
