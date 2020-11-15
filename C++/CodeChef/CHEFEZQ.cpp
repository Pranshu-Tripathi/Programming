#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0) , cin.tie(0),cout.tie(0);
#define ll long long
#define endl "\n"
#define And &&
#define Or ||
#define FOR(i,a,b)              for(int i = a; i < b; i++)
#define REV(i,a,b)              for(int i = a; i >= b; i--)
#define FORE(i,a,b)             for(int i = a; i <= b; i++)
#define pii                     pair<int,int>
#define pll                     pair< long long int, long long int> 
typedef 						long double ld;
typedef 						unsigned long long ull;
#define F                       first
#define S                       second
#define pb                      push_back

void solve()
{
    int n = 0; ll k = 0;
    cin >> n >> k;
    ll queries[n],i,sum = 0;
    ll update_day = 0;
    ll ans1 = __INT_MAX__;
    bool falg = false;
    FOR(i,0,n)
    {
        cin >> queries[i], sum+=queries[i];
        update_day += (queries[i] - k);
        if(update_day < 0 && !falg)
        {   
            falg = true;
            ans1 = i+1;
        }
    } 

    ll ans = (sum/k)+1;
    if(sum <= 3000001)
    cout << min(ans,ans1) << endl;
    else
    cout << ans << endl;
}

int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        solve();
    }
}